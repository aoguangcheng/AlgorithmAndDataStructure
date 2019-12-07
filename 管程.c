#define N 5
#define left (i - 1 + N) % N
#define right (i + 1) % N
typedef enum
{
    thinking,
    hungry,
    eating
} phil_state;

monitor dp
{
    phil_state state[N];
    semaphore mutex = 1;
    semaphore s[N];
    void test(int i)
    {
        if (state[i] == hungry && state[left(i)] != eating && state[left(i)] != eating)
        {
            state[i] = eating;
            V(s[i]);
        }
    }
    void get_forks(int i)
    {
        P(mutex);
        state[i] = hungry;
        test(i);
        V(mutex);
        P(s[i]);
    }
    void put_forks(int i)
    {
        P(mutex);
        state[i] = thinking;
        test(left(i));
        test(right(i));
        V(mutex);
    }
}
void philovopher(int process)
{
    while (true)
    {
        think();
        get_forks();
        eat();
        put_forks(process);
    }
}