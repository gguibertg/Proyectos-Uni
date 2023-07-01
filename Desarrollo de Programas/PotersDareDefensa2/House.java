
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.lang.Math;
import java.io.*;

/**
 * It represents the houses where the different characters are grouped so that each character must belong to one and only one of the houses.
 * His main task is to hold the group of its characters and send each one of them in each turn to the duel in Hogwarts.
 * 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */
public class House 
{
    private String name;
    private ArrayList<Character> characters;
    private Comparator<Character> order;
    private boolean reverse;

    /**
     *  Constructor of House
     */
    public House()
    {

        name = "";
        characters = new ArrayList<Character>();
        reverse = false;
        order = new OffensiveComparator();   

    }

    /**
     *  Parametric constructor of House
     *  @param String name of the house, boolean reverse true=reverseOrder, false=normalOrder
     *  Comparator<Character> order comparator of the order
     *  
     */
    public House(String name, boolean reverse, Comparator<Character> order)
    {

        this.name = name;
        characters = new ArrayList<Character>();
        this.reverse = reverse;
        this.order = order;   

    }

    /**
     *  Set the name of the House
     *  @param String name
     *  @return 
     */
    public void setName(String name)
    {

        this.name = name; 

    }

    /**
     *  Get the name of the House
     *  @param 
     *  @return String name of the House
     */
    public String getName()
    {

        return name; 

    }

    /**
     *  Add characters to the collection
     *  @param Character character who is gonna be added
     *  @return 
     */
    public void addCharacter(Character character)
    {

        characters.add(character);

    }

    /**
     *  Returns the first character
     *  @param 
     *  @return The first character
     */
    public Character first()
    {
        if(!this.characters.isEmpty()){
            return this.characters.get(0);
        }
        else{
            return null;   
        }
    }

    /**
     *  Remove the first Character of the house
     *  @param 
     *  @return 
     */
    public void removeFirst()
    {

        this.characters.remove(0);

    }

    /**
     *  Returns the character of the House 
     *  @param 
     *  @return ArrayList<Character> the collection of characters
     */
    public ArrayList<Character> getCharacters()
    {

        return this.characters;  

    }

    /**
     *  Returns the number of characters
     *  @param 
     *  @return int Number of characters
     */
    public int nChar()
    {
        if(!this.characters.isEmpty()){
            return this.characters.size();

        }else{
            return 0;   
        }
    }

    /**
     *  Set order on house
     *  @param Comparator order the order u wanna implement
     *  @return 
     */
    public void setOrder(Comparator order)
    {

        this.order = order; 

    }

    /**
     *  Returns the order of the House
     *  @param 
     *  @return Comparator The order is implemented on House 
     */
    public Comparator getOrder()
    {

        return this.order;

    }

    /**
     *  It order all the characters depending on reverse
     *  @param 
     *  @return 
     */
    public void orderCharacters()
    {
        if(reverse == true)
        {
            Collections.sort(characters, Collections.reverseOrder(order));
        }else{
            Collections.sort(characters, order);
        }
    }

    /**
     *  Prints all the characters to the terminal
     *  @param 
     *  @return 
     */
    public void showCharacters(PrintWriter printW){
        for(Character character : characters){
            printW.println("Character:<" + character.getName() +
                "> <e: " + Math.round(character.getEnergy()*100d)/100d +"> <o: "
                + Math.round(character.getOffensive()*100d)/100d + "> <d: "+ Math.round(character.getDefensive()*100d)/100d +
                "> <Wand: " + character.getWandName() + " (" + character.getWandType() + ")>");
        }
    }

    /**
     *  Returns the total Energy of the characters
     *  @param 
     *  @return double total energy of the characters
     */
    public double getTotalEnergy(){
        double totalEnergy=0;
        if(this.characters != null){

            for(Character character : characters){
                totalEnergy=totalEnergy+character.getEnergy();
            }
        }
        return totalEnergy;
    }

    /**
     *  Returns the total Points of the characters
     *  @param 
     *  @return double total points of the characters (def+off points)
     */

    public double getTotalPoints(){
        double totalPoints = 0;   
        if(this.characters != null){

            for(Character character : characters){
                totalPoints=totalPoints+character.getOffensive() + character.getDefensive();
            }
        }
        return totalPoints;

    }

}
