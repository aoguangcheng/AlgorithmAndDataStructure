#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/errno.h>
#include <signal.h>


#define phNum 5
#define left (phNum+phid-1)%phNum //phid表示哲学家编号
#define right (phid+1)%phNum


#define thinking 0
#define hungry 1
#define eating 2
#define thinktime 4
#define eattime 3 //调试完成之后改用枚举


union semun{
    int val;
    struct semid_ds* buf;
    unsigned short* array;
};


void p_operate(int semid,unsigned short semnum);
void v_operate(int semid,unsigned short semnum);
void think(int phid);
void eat(int phid);
void test(int phid,char* state,int semid);
void take_forks(int phid,char* state,int semid);
void put_forks(int phid,char* state,int semid);


void p_operate(int semid,unsigned short semnum){
    struct sembuf thesops;
    thesops.sem_num = semnum;//信号量下标
    thesops.sem_op = -1;//操作数
    thesops.sem_flg = SEM_UNDO;//操作标记
    semop(semid,&thesops,1);
    /*该函数对semid参数所标识的信号量集合中，由thesops参数指向
     * 的包含1个元素的结构体数组中的每个元素。
     * my comprehension:
     * 这是一个信号量集合，它有5个信号量
     * 以上表示对第semnum个信号量的操作
     * */
}
void v_operate(int semid,unsigned short semnum){
    struct sembuf thesops;
    thesops.sem_num = semnum;
    thesops.sem_op = 1;
    thesops.sem_flg = SEM_UNDO;
    semop(semid,&thesops,1);
}


void think(int phid){
    printf("I'm philosopher #%d,I will think for %d seconds...\n",phid,phid+thinktime);
    sleep(phid+thinktime);
}
void eat(int phid){
    printf("I'm philosopher #%d,I will eat for %d seconds...\n",phid,phid+eattime);
    sleep(phid+eattime);
}
void test(int phid,char* state,int semid){
    //测试编号为phid的哲学家是否能够就餐
    if(state[phid]==hungry && state[left] != eating && state[right] != eating){
    state[phid] = eating;
    printf("haha,philosopher #%d can eat now\n",phid);
    v_operate(semid,phid);
 }
 else if(state[phid] != hungry)
         printf("faint,philosopher #%d don't want to eat..\n",phid);
 else
         printf("oh~,philosopher #%d can not eat now.\n",phid);
}
void take_forks(int phid,char* state,int semid){
    p_operate(semid,phNum);
    state[phid] = hungry;
    printf("philosopher #%d is hungry.can he eat...\n",phid);
    test(phid,state,semid);
    v_operate(semid,phNum);
    p_operate(semid,phid);//得不到筷子则阻塞
}


void put_forks(int phid,char* state,int semid){
    p_operate(semid,phNum);
    state[phid] = thinking;
    printf("philosopher #%d have eaten...can his neighbours eat?..\n",phid);
    test(left,state,semid);//看左邻是否进餐
    test(right,state,semid);//看右邻是否进餐
    v_operate(semid,phNum);
}
void philosopher(int phid,char* state,int semid){
    while(1){
        think(phid);
        take_forks(phid,state,semid);
        eat(phid);
        put_forks(phid,state,semid);
    }
}


int main(int argc,char* argv[]){
    int semid,shmid,fori;
    char* state;
    pid_t pid;
    int mynum;
    union semun arg1;
    struct shmid_ds arg2;
    unsigned short array[phNum+1];//定义一个可以有6个信号量的集合。
    //信号从0开始数
    /*创建一个有6个信号量的集合*/   
    if((semid = semget(IPC_PRIVATE,phNum+1,0600|IPC_CREAT)) == -1){
        perror("semget error!");
        exit(1);
    }
    /*其实不用4096也行。用phNum就可以了，因为我们的共享内存只放一个state数组*/
    if((shmid = shmget(IPC_PRIVATE,4096,0600|IPC_CREAT)) == -1){
        /*删除这个信号量集合。
         * 只有针对信号量结合中的某个具体信号量的操作
         * 才会使用semnum操作即用到arg1，针对整个信号量不会用这个*/
        semctl(semid,0,IPC_RMID,arg1);
        perror("shmget error");
        exit(1);
    }
    /*多出来的那个资源值是1*/
    array[phNum] = 1;
    /*0~4的资源值都是0，每个哲学家一个信号量，初始值为0*/
    for(fori = 0;fori < phNum ;fori++) array[fori] = 0;
    arg1.array = array;//设置信号量数组初值
    /*SETALL设置信号量集合中的每个信号量的计数值，通过arg1.array输出*/
    if((semctl(semid,phNum+1,SETALL,arg1)) == -1){
        //设置各信号量的初始值 
        semctl(semid,0,IPC_RMID,arg1);
        shmctl(shmid,IPC_RMID,&arg2);
        perror("set default error!\n");
        exit(1);
    }
    /*void* shmat(int shmid,void* shmaddr,int shmflg)*/
    if((state = shmat(shmid,NULL,0)) == (char*)-1){
        /*(第一个0表示系统默认映射地址NULL也可以，
         * 第二个0表示以读写方式使用共享内存*/
        semctl(semid,0,IPC_RMID,arg1);
        shmctl(shmid,IPC_RMID,&arg2);
        perror("shmat error!");
        exit(1);
    }
    /*state数组表示哲学家状态state[0~4]*/
    for(fori = 0;fori < phNum ;fori++){
        state[fori] = thinking;//初始化状态数组
    }
    /*将进程对中断信号的处理设置为忽略
    signal(SIGINT,SIG_IGN);
    */
    for(fori = 1;fori <= phNum;fori++){
        //创建5个哲学家子进程
        pid = fork();
        if(pid == -1){
            perror("fork error!");
            exit(1);
        }
        if(pid == 0){
            //子进程执行代码
            mynum = fori - 1;
            /*设置子进程第SIGINT信号的处理过程
            signal(SIGINT,SIG_DFL);
            */
            break;
        }
    }
    if(pid > 0){
        //父进程等待子进程pid
        while(wait((char*)0)!=-1);
        //等待子进程执行结束，此处的(char*)0相当于NULL，即忽略返回状态
        semctl(semid,0,IPC_RMID,arg1);
        shmdt(state);
        shmctl(shmid,IPC_RMID,&arg2);
        printf("\n I'm monitor, all is over !!\n");
    }
    else
        /*因为state数组是共享的，而每个哲学家的子进程是相互独立的
         * 有自己的地址空间，在进程之间共享使用状态数组出现问题
         * 父进程创建一个共享内存区，并将状态数组地址链接到进程地址空间
         * my comprehension:
         * 这样就把state的状态写到共享内存里面了！,5个进程
         * 对同一个state数组进行操作*/
        philosopher(mynum,state,semid);
        //哲学家的代号是从0~4.
}
