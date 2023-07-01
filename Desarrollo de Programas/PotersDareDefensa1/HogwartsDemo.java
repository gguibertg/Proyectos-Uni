
/**
 * Main simulation class. 
 * First, initial data are loaded. 
 * Then, while is not the end of the simulation, the actions will be performed.
 *
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version 19/20
 */

import java.io.*;
public class HogwartsDemo
{

    public static void main(String[] args) {

        int turnNumber = 0;  //define the current turn number 
        int totalTurns = 10 ;    //define the total number of turns
        boolean endSimulation = false;   //define the end of the simulation
        FileWriter file = null;
        PrintWriter pw = null;
        try{

            //InitData initdata = new InitData();   //uncomment to try the simulation with others InitData
            InitData1 initdata = new InitData1();
            //InitData2 initdata = new InitData2();
            file = new FileWriter("output.txt");
            pw = new PrintWriter(file);
            //->call to method that shows the initial information

            Hogwarts.getInstance().showInformation(pw);

            //-> call to method that obtain the characters from the houses

            Hogwarts.getInstance().insertDuelists();

            while(turnNumber<totalTurns && Hogwarts.getInstance().getDuelistsSize()>1){
                pw.println("\nturn: <"+turnNumber+">");
                Hogwarts.getInstance().showDuelists(pw);

                pw.println();
                pw.println();
                pw.println();
                pw.println("duels:");
                pw.println("-----");

                Hogwarts.getInstance().duelistsFight(pw);

                pw.println();
                pw.println();
                pw.println("duels result:");
                pw.println("-----");

                //metodo que muestre el resultado de los duelos

                Hogwarts.getInstance().duelistsPlace(pw);  

                //-> call to method that obtain the characters from the houses

                Hogwarts.getInstance().insertDuelists();

                turnNumber++;
            }
            //-> call to method that write the final results
            Hogwarts.getInstance().showFinalInformation(pw);
        }  
        catch(Exception e){
            e.printStackTrace();
        }
        finally{
            try {
                // Nuevamente aprovechamos el finally para 
                // asegurarnos que se cierra el fichero.
                if (null != file)
                    file.close();
            } catch (Exception e2) {
                e2.printStackTrace();

            }

        }
    }
}
