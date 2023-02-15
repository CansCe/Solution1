package JavaBoosted.C2.B2;

import java.util.Scanner;
public class Employee {
    private String firtsName;
    private String lastName;
    private double salary;
    private int id;
    private int expYear=0;
    public Employee() {
    }

    public Employee(int id,String fn,String ln, double s,int expYear) {
        firtsName=fn;
        lastName=ln;
        salary = s;
        this.id=id;
        this.expYear=expYear;
    }

    public void setId(int id){
        this.id=id;
    }

    public void setFirstName(String fn) {
        firtsName = fn;
    }

    public void setLastName(String ln) {
        lastName = ln;
    }

    public String getFirstName() {
        return firtsName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getName(){
        return firtsName+" "+lastName;
    }

    public void setSalary(double s) {
        salary = s;
    }

    public double getSalary() {
        return salary;
    }

    public int raiseSalary(int percent){
        salary = salary + salary*percent/100;
        return (int)salary;
    }

    public int getAnnualSlary(){
        return (int)salary*12;
    }

    public int getId(){
        return id;
    }
    public int getExpYear(){
        return expYear;
    }
    public int getSalarybyExpYear(){
        if(expYear==2){
            return raiseSalary(5);
        }
        else if(expYear==5){
            return raiseSalary(10);
        }
        else if(expYear==10){
            return raiseSalary(15);
        }
        return raiseSalary(20);
    }
    public void nhap(){
        Scanner sc =new Scanner(System.in);
        System.out.println("Nhap ten: ");
        firtsName=sc.nextLine();
        System.out.println("Nhap ho: ");
        lastName=sc.nextLine();
        System.out.println("Nhap luong: ");
        salary=sc.nextDouble();
        System.out.println("Nhap id: ");
        id=sc.nextInt();
        System.out.println("Nhap nam kinh nghiem: ");
        expYear=sc.nextInt();
        sc.close();
    }
    public String toString(){
        return "Name: " + firtsName+" "+lastName + " Salary: " + salary;
    }

}