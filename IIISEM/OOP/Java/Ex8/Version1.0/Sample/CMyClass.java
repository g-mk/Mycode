import java.util.*;
class CEmp implements Cloneable
{
 public CEmp()
 {
  name="";
  age=0;
 }
 public CEmp(String s,int n)
 {
  name=s;
  age=n;
 }
 public void display()
 { 
  System.out.println("Name:"+name+"Age:"+age);
 }
 public Object clone()throws CloneNotSupportedException
 {
  /*CEmp s=new CEmp();
  s.name=name;
  s.age=age;
  return s;*/
   return super.clone();
 }
 public void setAge(int n)
 {
  age=n;
 }
 private String name;
 private int age;
}
public class CMyClass
{
 public static void main(String[] args)
 {
  try
 {
  CEmp eobj=new CEmp("AB",18);
  eobj.display();
  CEmp nobj=(CEmp)eobj.clone();
  nobj.display();
  nobj.setAge(15);
  eobj.display();
  nobj.display();
 }
 catch(CloneNotSupportedException se)
 {
 }
 }
}

