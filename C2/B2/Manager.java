package JavaBoosted.C2.B2;

public class Manager extends Employee{
    private int teamID;
    private String teamName;
    Employee[] team = new Employee[10];
    public Manager()
    {
        super();
    }
    public Manager(int id,String fn,String ln, double s, int tid, String tname, Employee[] t){
        super(id, fn, ln, s, id);
        teamID=tid;
        teamName=tname;
        team=t;
    }
    public Manager(Employee e, int id, String name, Employee[] t){
        super(e.getId(),e.getFirstName(),e.getLastName(),e.getSalary(),e.getId());
        teamID=id;
        teamName=name;
    }
    public int getTeamID() {
        return teamID;
    }
    public String getTeamName() {
        return teamName;
    }
    public void setTeamID(int id) {
        teamID = id;
    }
    public void setTeamName(String name) {
        teamName = name;
    }
    public void addEmployee(Employee e){
        for(int i=0;i<team.length;i++){
            if(team[i]==null){
                team[i]=e;
                break;
            }
        }
    }
    public void removeEmployee(Employee e){
        for(int i=0;i<team.length;i++){
            if(team[i]==e){
                team[i]=null;
                break;
            }
        }
    }
    public double getTeamSalary(){
        double sum=0;
        for(int i=0;i<team.length;i++){
            if(team[i]!=null){
                sum+=team[i].getSalary();
            }
        }
        return sum;
    }
    @Override public  String toString(){
        return "Name: " + getFirstName()+" "+getLastName() + " Salary: " + getSalary() + " TeamID: " + teamID + " TeamName: " + teamName;
    }
    
}
