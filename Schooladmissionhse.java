
package schooladmissionhse;
/*
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Random;
*/

import java.io.*;   
import java.sql.*;  
import java.util.Random; 

public class Schooladmissionhse {

    public static void main(String arg[]) throws IOException  
      {  
            int regno,b_seat=30,c_seat=30,a_seat=3;
	    String name;  
            int tamil,english,maths,science,social,total;
		    
		    BufferedReader br=new BufferedReader(new InputStreamReader (System.in));  
            System.out.println("\n\n\t**** HIGHER SECONDARY ADMISSION *****"); 
           try  
           {  			
      	    Class.forName("com.mysql.cj.jdbc.Driver");  
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/school","root","");  
               int wish=1;
            do  
                {  
                    System.out.println("");
                    System.out.println("********************************************************************************************");
                    System.out.println("1.REGISTRATION\t 2.BIOLOGY\t 3.COMPUTER SCIENCE\t 4.ARTS\t 5.EXIT."); 
                    System.out.println("********************************************************************************************");
                    int ch = Integer.parseInt(br.readLine());
                    switch(ch)  
                    {  
                        case 1:  
	
                            try  
                            {       int choice,bin_seat=0,cin_seat=0,ain_seat=0;
                            System.out.print("Enter Name: ");  
                            name = br.readLine();  
                            System.out.println("Enter the 10th Register number");  
                            regno = Integer.parseInt(br.readLine());  
                            System.out.println("Enter tamil mark : ");
                            tamil = Integer.parseInt(br.readLine());
                            System.out.println("Enter English mark : ");
                            english = Integer.parseInt(br.readLine());
                            System.out.println("Enter maths mark : ");
                            maths = Integer.parseInt(br.readLine());
                            System.out.println("Enter science mark : ");
                            science = Integer.parseInt(br.readLine());
                            System.out.println("Enter social mark : ");
                            social = Integer.parseInt(br.readLine());
                            total=tamil+english+maths+science+social;
                            System.out.print("\nYour total : ");System.out.print(total);
                            System.out.print("\nYour are eligible for below listed courses: choose your choice");
                            if(total>=450)
                            {
                                System.out.println("\n1. BIOLOGY \n2. COMPUTER SCIENCE\n3. ARTS\nYour choice : ");
                                choice = Integer.parseInt(br.readLine());
                                Statement stmt1=con.createStatement();  
                                if(choice==1){
                                                                            
                                Statement stmt2=con.createStatement();  
                                ResultSet rs2=stmt2.executeQuery("SELECT * FROM biology");
                                while(rs2.next()){bin_seat=bin_seat+1;}
                                if(bin_seat>=b_seat){System.out.print("\n\nSeats are filled, try another course");}
                                else{
                                String qry="insert into biology(name,regno,tamil,english,maths,science,social,total) values ('"+name+"' ,"+regno+","+tamil+","+english+","+maths+","+science+","+social+","+total+")";
                                stmt1.executeUpdate(qry);
                                System.out.println("\nYour admission is successfull");}}
                                else if(choice==2){    
                                Statement stmt2=con.createStatement();  
                                ResultSet rs2=stmt2.executeQuery("SELECT * FROM cs");
                                                        while(rs2.next()){cin_seat=cin_seat+1;}
                                                                        if(cin_seat>=c_seat){System.out.print("\n\nSeats are filled, try another course");}
                                                                        else{
                                                                        String qry="insert into cs(name,regno,tamil,english,maths,science,social,total) values ('"+name+"' ,"+regno+","+tamil+","+english+","+maths+","+science+","+social+","+total+")";
                                                                        stmt1.executeUpdate(qry);
                                                                        System.out.println("\nYour admission is successfull");
                                                                        }}
                                                                        else if(choice==3){
                                                                            
                                                                        Statement stmt2=con.createStatement();  
                                                                        ResultSet rs2=stmt2.executeQuery("SELECT * FROM arts");
                                                                        while(rs2.next()){ain_seat=ain_seat+1;}
                                                                        if(ain_seat>=a_seat){System.out.print("\n\nSeats are filled, try another course");}    
                                                                        else{
                                                                        String qry="insert into arts(name,regno,tamil,english,maths,science,social,total) values ('"+name+"' ,"+regno+","+tamil+","+english+","+maths+","+science+","+social+","+total+")";
                                                                        stmt1.executeUpdate(qry);    
                                                                        System.out.println("\nYour admission is successfull");
                                                                        }}
                                                                        else System.out.println("Wrong input");
                                                                        }
                                                                        
                                                                        else if(total>=400)
                                                                        {System.out.println("\n1. COMPUTER SCIENCE\n2. ARTS\nYour choice : ");
                                                                        choice = Integer.parseInt(br.readLine());
                                                                        Statement stmt1=con.createStatement();  
                                                                        if(choice==1){
                                                                            
                                                                        Statement stmt2=con.createStatement();  
                                                                        ResultSet rs2=stmt2.executeQuery("SELECT * FROM cs");
                                                                        while(rs2.next()){bin_seat=bin_seat+1;}
                                                                        if(cin_seat>=c_seat){System.out.print("\n\nSeats are filled, try another course");}
                                                                        else{
									String qry="insert into cs(name,regno,tamil,english,maths,science,social,total) values ('"+name+"' ,"+regno+","+tamil+","+english+","+maths+","+science+","+social+","+total+")";
                                                                        stmt1.executeUpdate(qry);
                                                                        System.out.println("\nYour admission is successfull");}}
                                                                        else if(choice==2){
                                                                            
                                                                        Statement stmt2=con.createStatement();  
                                                                        ResultSet rs2=stmt2.executeQuery("SELECT * FROM arts");
                                                                        while(rs2.next()){bin_seat=bin_seat+1;}
                                                                        if(ain_seat>=a_seat){System.out.print("\n\nSeats are filled, try another course");}
                                                                        else{
                                                                            
                                                                        String qry="insert into arts(name,regno,tamil,english,maths,science,social,total) values ('"+name+"' ,"+regno+","+tamil+","+english+","+maths+","+science+","+social+","+total+")";
                                                                        stmt1.executeUpdate(qry); 
                                                                        System.out.println("\nYour admission is successfull");
                                                                        }}
                                                                        else {System.out.println("Wrong input");}
                                                                        }
                                                                        
                                                                        else 
                                                                        {System.out.println("\n1. ARTS\nYour choice : ");
                                                                        choice = Integer.parseInt(br.readLine());
                                                                        Statement stmt1=con.createStatement();
                                                                        if(choice==1){
                                                                            
                                                                        Statement stmt2=con.createStatement();  
                                                                        ResultSet rs2=stmt2.executeQuery("SELECT * FROM arts");
                                                                        while(rs2.next()){bin_seat=bin_seat+1;}
                                                                        if(ain_seat>=a_seat){System.out.print("\n\nSeats are filled, try another course");}
                                                                        else{
                                                                        String qry="insert into arts(name,regno,tamil,english,maths,science,social,total) values ('"+name+"' ,"+regno+","+tamil+","+english+","+maths+","+science+","+social+","+total+")";
                                                                        stmt1.executeUpdate(qry);
                                                                        System.out.println("\nYour admission is successfull");
                                                                        }}
                                                                        else System.out.println("Wrong input");}
                                                                       
                                                                }  
								catch(Exception e)  
								{  
									System.out.println("Error in creating Account");  
								}  
						  break;                            
                          case 2:  
								int choice,bin_seat=0;
                                                                System.out.println("1. List of Students\n2. View particular student\n3. Remaining seats available\n Your choice : "); 
								choice = Integer.parseInt(br.readLine());
                                                                if(choice==1){
								Statement stmt2=con.createStatement();  
								ResultSet rs2=stmt2.executeQuery("SELECT * FROM biology");  
									while(rs2.next())  
									{	
                                                                            
									    System.out.println("---------------------------------");
										
										System.out.println("Name  : "+rs2.getString(1));
										System.out.println("Register no. : "+rs2.getInt(2));
                                                                                System.out.println("Total : "+rs2.getInt(8));
										System.out.println("---------------------------------");
										System.out.println("\n");  
									}}
                                                                else if(choice==2){
                                                                System.out.println("Enter student register number : "); 
								int reg = Integer.parseInt(br.readLine());
								Statement stmt2=con.createStatement();  
								ResultSet rs2=stmt2.executeQuery("SELECT * FROM biology WHERE regno = "+reg);  
									while(rs2.next())  
									{
									//	System.out.println("\n");  
									    System.out.println("---------------------------------");
										//System.out.println("Name    : "+rs2.getInt(1));
										System.out.println("Name  : "+rs2.getString(1));
										System.out.println("Register no. : "+rs2.getInt(2));  
                                                                                System.out.println("Total : "+rs2.getInt(8));
										System.out.println("---------------------------------");
										System.out.println("\n");  
									}}
                                                                else if(choice==3){
                                                                Statement stmt2=con.createStatement();  
								ResultSet rs2=stmt2.executeQuery("SELECT * FROM biology");
                                                                while(rs2.next()){bin_seat=bin_seat+1;}
                                                                System.out.print("\nTotal seats intake : ");
                                                                System.out.print(b_seat);
                                                                System.out.print("\nRemaining seats available : ");
                                                               
                                                                    System.out.print((b_seat)-(bin_seat));
                                                                
                                                                }
                                                                else System.out.println("Wrong input");
						//  con.close();  
                          break;  
                            
                         case 3:  
								int cin_seat=0;
                                                                System.out.println("1. List of Students\n2. View particular student\n3. Remaining seats available\n Your choice : "); 
								choice = Integer.parseInt(br.readLine());
                                                                if(choice==1){
								Statement stmt2=con.createStatement();  
								ResultSet rs2=stmt2.executeQuery("SELECT * FROM cs");  
									while(rs2.next())  
									{	
									
									    System.out.println("---------------------------------");
										
										System.out.println("Name  : "+rs2.getString(1));
										System.out.println("Register no. : "+rs2.getInt(2));
                                                                                System.out.println("Total : "+rs2.getInt(8));
										System.out.println("---------------------------------");
										System.out.println("\n");  
									}}
                                                                else if(choice==2){
                                                                System.out.println("Enter student register number : "); 
								int reg = Integer.parseInt(br.readLine());
								Statement stmt2=con.createStatement();  
								ResultSet rs2=stmt2.executeQuery("SELECT * FROM cs WHERE regno = "+reg);  
									while(rs2.next())  
									{	
									//	System.out.println("\n");  
									    System.out.println("---------------------------------");
										//System.out.println("Name    : "+rs2.getInt(1));
										System.out.println("Name  : "+rs2.getString(1));
										System.out.println("Register no. : "+rs2.getInt(2));  
                                                                                System.out.println("Total : "+rs2.getInt(8));
										System.out.println("---------------------------------");
										System.out.println("\n");  
									}}
                                                                else if(choice==3){
                                                                
                                                                Statement stmt2=con.createStatement();  
								ResultSet rs2=stmt2.executeQuery("SELECT * FROM cs");
                                                                while(rs2.next()){cin_seat=cin_seat+1;}
                                                                System.out.print("\nTotal seats intake : ");
                                                                System.out.print(c_seat);
                                                                System.out.print("\nRemaining seats available : ");
                                                                System.out.print((c_seat)-(cin_seat));
                                                                }
                                                                else System.out.println("Wrong input");
						//  con.close();  
                          break;  
                            
                          case 4:  
								int ain_seat=0;
                                                                System.out.println("1. List of Students\n2. View particular student\n3. Remaining seats available\n Your choice : "); 
								choice = Integer.parseInt(br.readLine());
                                                                if(choice==1){
								Statement stmt2=con.createStatement();  
								ResultSet rs2=stmt2.executeQuery("SELECT * FROM arts");  
									while(rs2.next())  
									{	
									
									    System.out.println("---------------------------------");
										
										System.out.println("Name  : "+rs2.getString(1));
										System.out.println("Register no. : "+rs2.getInt(2));
                                                                                System.out.println("Total : "+rs2.getInt(8));
										System.out.println("---------------------------------");
										System.out.println("\n");  
									}}
                                                                else if(choice==2){
                                                                System.out.println("Enter student register number : "); 
								int reg = Integer.parseInt(br.readLine());
								Statement stmt2=con.createStatement();  
								ResultSet rs2=stmt2.executeQuery("SELECT * FROM arts WHERE regno = "+reg);  
									while(rs2.next())  
									{	
									//	System.out.println("\n");  
									    System.out.println("---------------------------------");
										//System.out.println("Name    : "+rs2.getInt(1));
										System.out.println("Name  : "+rs2.getString(1));
										System.out.println("Register no. : "+rs2.getInt(2));  
                                                                                System.out.println("Total : "+rs2.getInt(8));
										System.out.println("---------------------------------");
										System.out.println("\n");  
									}}
                                                                else if(choice==3){
                                                                
                                                                Statement stmt2=con.createStatement();  
								ResultSet rs2=stmt2.executeQuery("SELECT * FROM arts");
                                                                while(rs2.next()){ain_seat=ain_seat+1;}
                                                                System.out.print("\nTotal seats intake : ");
                                                                System.out.print(a_seat);
                                                                System.out.print("\nRemaining seats available : ");
                                                                System.out.print((a_seat)-(ain_seat));}
                                                                else System.out.println("Wrong input");
						//  con.close();  
                          break;    

                          case 5:  
								System.out.println("Thank You !");
								wish=0;
                          break;  
                            
                          default: System.out.println("Invalid Option");  
                     }  
//					 con.close();  
                }while(wish==1);  
				System.out.println("DB Connection closed!");  
				con.close();  
		   }
           catch(Exception e)  
           {  
                System.out.println("ERROR-Choose the correct option -  "+e);  
           }
}
}
