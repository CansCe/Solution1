package JavaBoosted.C2.B1;

public class Rectangle {
    private double width;
    private double length;
    private String color;

    public Rectangle() {
        width = 1.0;
        length = 1.0;
        color = "red";
    }

    public Rectangle(double w, double l) {
        width = w;
        length = l;
        color = "red";
    }

    public double getWidth() {
        return width;
    }

    public double getLength() {
        return length;
    }

    public double getArea() {
        return width * length;
    }

    public String toString(){
        return "Width: " + width + " Length: " + length + " Color: " + color;
    }
}