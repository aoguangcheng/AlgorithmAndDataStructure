import java.util.Scanner;
interface Service{
    public abstract void work();
}

//Deposits
public class Deposits implements Service {
    public void work(){
        System.out.println("Deposits Working");
    }
}

//Withdrawal
public class Withdrawal implements Service{
    public void  work(){
        System.out.println("Withdrawal Working");
    }
}

//TransferAccount
public class TransferAccount implements Service{
    public void  work(){
        System.out.println("TransferAccount Working");
    }
}

//CheckBalance
public class CheckBalance implements Service{
    public void  work(){
        System.out.println("CheckBalance Working");
    }
}

//CheckDetail
public class CheckDetail implements Service{
    public void  work(){
        System.out.println("CheckDetail Working");
    }
}

//Facade
public class Facade {
    Deposits deposits;
    Withdrawal withdrawal;
    TransferAccount transferAccount;
    CheckBalance checkBalance;
    CheckDetail checkDetail;

    public Facade() {
        deposits = new Deposits();
        withdrawal = new Withdrawal();
        transferAccount = new TransferAccount();
        checkBalance = new CheckBalance();
        checkDetail = new CheckDetail();
    }

    public void method_deposits(){
        this.deposits.work();
    }

    public void method_withdrawal(){
        this.withdrawal.work();
    }

    public void method_transferAccount(){
        this.transferAccount.work();
    }

    public void method_checkBalance(){
        this.checkBalance.work();
    }

    public void method_checkDetail(){
        this.checkDetail.work();
    }

}

//main
public class Client{
    public static void main(String[] args) {
        Facade facade;
        System.out.println("Hello, Please choose the business to handled :");
        System.out.println("deposits -- dp, withdrawal -- wd, transferAccount -- ta, checkBalance -- cb, checkDetail -- cd, exit");
        Scanner scanner = new Scanner(System.in);
        String str;
        str = scanner.nextLine();
        while(str != "exit")
        {
            switch(str){
                case "exit" :
                    System.out.println("finish!");
                    break;
                case "dp" :
                    facade.method_deposits();
                    break;
                case "wd" :
                    facade.method_withdrawal();
                    break;
                case "ta" :
                    facade.method_transferAccount();
                    break;
                case "cb" :
                    facade.method_checkBalance();
                    break;
                case "cd" :
                    facade.method_checkDetail();
                    break;
            }
            str = scanner.nextLine();
        }
    }
}