
import java.util.*;
import java.lang.Math;
import java.lang.Comparable;
import java.io.*;
/**
 * A collection that stores the different houses of the simulation.
 * This structure will allow efficient access to each house using its name (whose values will be unique) as the key.
 * It represents the castle where the characters compete.
 * Its main mission is to store information about houses, characters, duels and their results.
 * 
 * Hogwarts has the following attributes:
 *          -houses: Houses is a HashMap that is a collection of key-value pairs without a particular order whose implementation is based on hash table
 *          -newWands: A TreeSet that stores the newWands. TreeSet is a sorted collections of elements without duplicate elements.
 *          -duelists: An ArrayList that stores the characters who are going to fight sorted by energy. ArrayList is a sequential collection of elements implemented as an array.
 *          -dungeon: An ArrayList that contains the characters without Energy.
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */

public class Hogwarts{
    private static Hogwarts instance;
    private Map <String,House> houses;
    private TreeSet <Wand> newWands;
    private ArrayList<Character> duelists;
    private ArrayList<Character> dungeon;

    /**
     * Constructor for objects of class Hogwarts
     */
    private Hogwarts()
    {        
        houses = new HashMap<String,House>(); 
        duelists = new ArrayList<Character>(); 
        newWands = new TreeSet<Wand>(new WandNameComparator());
        dungeon = new ArrayList<Character>();
    }

    /**
     * 
     *Implement “lazy initialization” inside the static method.
     *It creates a new object on its first call and put it into 
     *the static field.
     *
     *@return instance The instace created.
     */

    public synchronized static Hogwarts getInstance(){
        if(instance == null){
            instance = new Hogwarts();   
        }
        return instance;
    }

    /**
     *  Parametric constructor of Hogwart's class
     *  @param HashMap <String,House> houses collection of houses,
     *         ArrayList <Wand> newWands collection of Wands,
     *         ArrayList<Character> duelists collection of duelists,
     *         HashSet<Character> dungeon collection of dungeons
     *  
     */
    private Hogwarts(HashMap <String,House> houses, TreeSet <Wand> newWands, ArrayList<Character> duelists,ArrayList<Character> dungeon)
    {

        this.houses = houses;
        this.newWands = newWands;
        this.duelists = duelists;
        this.dungeon = dungeon;

    }

    /**
     *  insert the characters who are going to fight
     *  @param 
     *  @return 
     */

    public void insertDuelists(){                                
        for (Map.Entry<String, House> house : houses.entrySet()) {
            if (house.getValue().nChar() > 0){
                duelists.add(duelists.size(),house.getValue().first());  
            }
        }        
        Collections.sort(this.duelists, new EnergyComparator());
    }

    /**
     *  Its takes the first character to fight, then remove it
     *  and add it to the collection at the end 
     *  @param 
     *  @return 
     */
    public void duelistsFight(PrintWriter printW)
    {
        int i;
        Character a;

        for(i = 0; i < duelists.size(); i++){
            a = duelists.get(0);
            fightOthers(a,printW);
            duelists.remove(0);
            duelists.add(a);
        }
    }

    /**
     *  Print into the terminal the fights
     *  @param Character initialDuelist The first character who's gonna fight
     *  @return 
     */
    public void fightOthers(Character initialDuelist, PrintWriter printW){        
        for (Character duelist : duelists){
            if(initialDuelist != duelist){

                printW.println("<"+initialDuelist.getName()+">"+" is dueling against "+
                    "<"+duelist.getName()+">");
                if(initialDuelist.getEnergy() > 0 && duelist.getEnergy() > 0){
                    printW.println("attack points of "+"<"+initialDuelist.getName()+
                        "> are: <"+Math.round(initialDuelist.attack()*100d)/100d +">");
                    printW.println("resistance points of "+"<"+duelist.getName()+
                        "> are: <"+Math.round(duelist.resistance()*100d)/100d+">");
                    initialDuelist.fight(duelist);
                    printW.println("the remaining energy of <"+duelist.getName()+
                        "> after the duel is: <"+ Math.round(duelist.getEnergy()*100d)/100d +">");
                    printW.println();
                }
            }
        }
    }

    /**
     *  add to the house the character after they fights if they have energy
     *  @param 
     *  @return 
     */

    public void duelistsPlace(PrintWriter printW){

        showDuelistsFate(printW);
        for (Map.Entry<String, House> house : houses.entrySet()) {
            if (house.getValue().first()!=null){
                if (house.getValue().first().getEnergy()>0){                    
                    house.getValue().getCharacters().add(house.getValue().first());                     
                }else{                    
                    dungeon.add(house.getValue().first());                  
                }
                house.getValue().getCharacters().remove(0);
            }
        }
        duelists.clear();
    }

    /**
     *  It shows where the character goes, to dungeon or back into the house,
     *  it also put a newWand to the Character
     *  @param 
     *  @return 
     */

    public void showDuelistsFate(PrintWriter printW) {
        for(Character duelist : duelists){
            if(duelist.getEnergy()>0){
                printW.println("character:<"+duelist.getName()+"> <e: "+ Math.round(duelist.getEnergy()*100d)/100d + "> <o: "+  Math.round(duelist.getOffensive()*100d)/100d+"> <d: "
                    +  Math.round(duelist.getDefensive()*100d)/100d +
                    "> <wand: "+duelist.getWandName()+"   "+"("+duelist.getWandType()+")> returns to the house");                     
                if(newWands.size()>0){
                    duelist.changeWand(newWands.first());
                    printW.println("new wand assigned: <"+ newWands.first().getName()+" (class "+newWands.first().getType()+")>");
                    newWands.remove(newWands.first());   

                }
            }else{
                printW.println("character:<"+duelist.getName()+"> <e: "+Math.round(duelist.getEnergy()*100d)/100d+"> <o: "+Math.round(duelist.getOffensive()*100d)/100d
                    +"> <d: "+Math.round(duelist.getDefensive()*100d)/100d+
                    "> <wand: "+duelist.getWandName()+"   "+"("+duelist.getWandType()+")> goes to the dungeon"); 
            }
        }
    }

    /**
     *  Inserts the wand into the collection
     *  @param Wand wand u wanna insert into the collection
     *  @return 
     */

    public void addWand(Wand wand){

        newWands.add(wand);

    }

    /**
     *  Inserts the House into the collection
     *  @param String name you wanna insert into the collection, House house u wanna insert
     *  @return 
     */
    public void addHouse(String name, House house){ 

        this.houses.put(name,house);

    }   

    /**
     *  Returns the Size of the Duelist's collection
     *  @param 
     *  @return int Number of duelists
     */
    public int getDuelistsSize(){

        return this.duelists.size();  

    }

    /**
     *  Print the information of the houses and wands into the terminal
     *  @param 
     *  @return 
     */

    public void showInformation(PrintWriter printW){
        printW.println("Houses:");
        for (Map.Entry<String, House> house : houses.entrySet()) {
            printW.println("house: "+"<"+house.getValue().getName()+">");
            house.getValue().showCharacters(printW);
        }
        printW.println("new wands:");
        printW.println("-------------------------");

        Iterator<Wand> wand = newWands.iterator();
        while(wand.hasNext()){
            Wand wandn = wand.next();
            printW.println("wand: "+"<"+wandn.getName()+" ("+wandn.getType()+")>");    
        }

    }

    /**
     *  Print the information of duelists into the terminal
     *  @param 
     *  @return 
     */

    public void showDuelists(PrintWriter printW){
        printW.println("characters who are going to duel:");
        printW.println("----------------------------------");
        Iterator<Character> dN = duelists.iterator();

        while(dN.hasNext()){
            Character d = dN.next();
            printW.println("character:<"+d.getName()+"> <e:"+ Math.round(d.getEnergy()*100d)/100d+
                "> <o:"+Math.round(d.getOffensive()*100d)/100d+"> <d:"+Math.round(d.getDefensive()*100d)/100d+"> <wand: "+ d.getWandName()+
                " ("+d.getWandType()+")");
        }

    }

    /**
     *  Returns the house with more Characters, if two houses has the same 
     *  characters, it returns the one that their character has more energy
     *  @param 
     *  @return House The winner house
     */

    public House getWinnerHouse(){
        int maxSize=0;
        House winnerHouse;
        winnerHouse= new House ();
        for (Map.Entry<String, House> house : houses.entrySet()) {

            if(house.getValue().nChar() > maxSize){
                maxSize=house.getValue().nChar();   
                winnerHouse = house.getValue();
            }

            if(house.getValue().nChar() == winnerHouse.nChar()){

                if(house.getValue().getTotalEnergy() > winnerHouse.getTotalEnergy()){

                    winnerHouse = house.getValue();

                }else{
                    if(house.getValue().getTotalEnergy() == winnerHouse.getTotalEnergy()){
                        if(house.getValue().getTotalPoints() < winnerHouse.getTotalPoints()){
                            winnerHouse = house.getValue();
                        }                                                          
                    }
                }

            }
        }
        return winnerHouse;
    }

    /**
     *  Print the information of the winner's house
     *  @param 
     *  @return 
     */
    public void showFinalInformation(PrintWriter printW){

        printW.println("end of the simulation:");
        printW.println("----------------------------------");
        printW.println("Houses:");
        printW.println("-------------------");
        for (Map.Entry<String, House> house : houses.entrySet()) {
            printW.println("house: "+"<"+house.getValue().getName()+">");
            house.getValue().showCharacters(printW);
        }
        printW.println("new wands:");
        printW.println("-------------------------");
        for(Wand wand : newWands){ 
            printW.println("wand: "+"<"+wand.getName()+" ("+wand.getType()+")>");
        } 

        printW.println("dungeon characters:");
        printW.println("-------------------------");

        for(Character d : dungeon){
            printW.println("character: "+"<"+d.getName()+
                ">"+"<"+"e: "+Math.round(d.getEnergy()*100d)/100d+">"+"<"+"o: "
                +Math.round(d.getOffensive()*100d)/100d +">"+"<"+"d: "+Math.round(d.getDefensive()*100d)/100d+">"+
                "<wand: "+d.getWandName()+" ("+d.getWandType()+
                ")>");

        }

        printW.println("the winner house is: ");
        printW.println("-------------------------");

        printW.println("house: "+"<"+getWinnerHouse().getName()+">");
        getWinnerHouse().showCharacters(printW);    
    }


    
}