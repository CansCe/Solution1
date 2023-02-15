package JavaBoosted.C2.B2;
import java.util.*;

public class MainTest {
    public static void main(){
        Scanner sc = new Scanner(System.in);
        Manager m = new Manager();
        System.out.print("Nhap ten Quan ly:");
        m.setFirstName(sc.nextLine());
        System.out.print("Nhap ho Quan ly:");
        m.setLastName(sc.nextLine());
        System.out.print("Nhap luong Quan ly:");
        m.setSalary(sc.nextDouble());
        System.out.print("Nhap ma Team Quan Ly:");
        m.setTeamID(sc.nextInt());
        sc.nextLine();
        System.out.print("Nhap cac thanh vien trong Team: ");
        for(int i=0;i<m.team.length;i++){
            m.team[i].nhap();
        }
        System.out.print("1- Tim kiem theo ID;"+"\n"+" 2- Tim kiem theo ten"+ "\n"+ " 3- Tim kiem theo luong va tiep tuc tiem kiem theo cac 1 va 2");
        int key =0;
        System.out.print("Nhap lua chon:");
        key = sc.nextInt();
        char choice ;
        do{
            switch(key){
                case 1:
                    System.out.print("Nhap id can tim:");
                    int id = sc.nextInt();
                    for(int i=0;i<m.team.length;i++){
                        if(m.team[i]!=null){
                            if(m.team[i].getId()==id){
                                System.out.print(m.team[i].toString());
                            }
                        }
                    }
                    break;
                case 2:
                    System.out.print("Nhap ten can tim:");
                    String name = sc.nextLine();
                    for(int i=0;i<m.team.length;i++){
                        if(m.team[i]!=null){
                            if(m.team[i].getFirstName().equals(name)){
                                System.out.print(m.team[i].toString());
                            }
                        }
                    }
                    break;
                case 3:
                    System.out.print("Nhap luong can tim:");
                    double salary = sc.nextDouble();
                    for(int i=0;i<m.team.length;i++){
                        if(m.team[i]!=null){
                            if(m.team[i].getSalary()==salary){
                                System.out.print(m.team[i].toString());
                            }
                        }
                    }
                    int key2;
                    System.out.print("Nhap lua chon:(Tim theo cach 1 va 2)");
                    key2 = sc.nextInt();
                    switch(key2){
                        case 1:
                            System.out.print("Nhap id can tim:");
                            int id2 = sc.nextInt();
                            for(int i=0;i<m.team.length;i++){
                                if(m.team[i]!=null){
                                    if(m.team[i].getId()==id2){
                                        System.out.print(m.team[i].toString());
                                    }
                                }
                            }
                            break;
                        case 2:
                            System.out.print("Nhap ten can tim:");
                            String name2 = sc.nextLine();
                            for(int i=0;i<m.team.length;i++){
                                if(m.team[i]!=null){
                                    if(m.team[i].getFirstName().equals(name2)){
                                        System.out.print(m.team[i].toString());
                                    }
                                }
                            }
                            break;
                        default:
                            System.out.print("Nhap sai lua chon!");
                            break;
                    }
                    break;
                default:
                    System.out.print("Nhap sai lua chon!");
                    break;
            }
            System.out.print("Cac nhan vien co nam lam viec tren 30 la: ");
            for(int i=0;i<m.team.length;i++){
                if(m.team[i]!=null){
                    if(m.team[i].getExpYear()>30){
                        System.out.print("." + m.team[i].toString());
                    }
                }
            }
            System.out.println(".");

            System.out.print("Ban co muon tiep tuc khong?(y/n)");
            choice = sc.next().charAt(0);            
        }while(choice == 'y' || choice == 'Y');
        sc.close();
    }
    
}
