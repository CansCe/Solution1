package JavaBoosted.C2.B2;

public class testEmployee {
    public static void main(String[] args) {
        Employee[] team = new Employee[10];
        for(int i=0;i<team.length;i++){
            team[i]=new Employee(i,"fn"+i,"ln"+i,1000+i,i);
        }
        
    }
}
