
/**
 * Class to init data of the simulation. 
 * It could be used alto to write finals results.
 * 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version 19/20
 */
import java.util.*;
public class InitData2
{
    public InitData2()
    {
        initData2();

    }

    private void initData2()
    {

        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Ivy"));
        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Larch"));
        Hogwarts.getInstance().addWand(new HollyDefensive("Rowan"));
        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Yew"));
        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Hazel"));
        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Pine"));
        Hogwarts.getInstance().addWand(new HollyDefensive("Tamarack"));
        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Spruce"));
        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Pear"));
        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Laurel"));
        Hogwarts.getInstance().addWand(new HollyDefensive("Cypress"));
        Hogwarts.getInstance().addWand(new HollyDefensive("Ebony"));
        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Reed"));
        Hogwarts.getInstance().addWand(new HollyDefensive("Aspen"));
        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Walnut"));

        
        
        
        
        
        
        House gryffindor = new House("Gryffindor",false, new DefensiveComparator());

        Character harry = new OffensiveCharacter("Harry Potter",new HollyDefensive("HarryW"));
        harry = new InvigorationPotioned(harry); 
        harry = new FelixFelicisPotioned(harry);

        Character hermione = new OffensiveCharacter("Hermione Granger", new HollyDefensive("HermioneW")); 
        hermione = new InvigorationPotioned(hermione);
        hermione = new FelixFelicisPotioned(hermione);

        Character ron = new OffensiveCharacter("Ron Weasley", new HollyDefensive("RonW"));
        ron = new FelixFelicisPotioned(ron); 

        

        gryffindor.addCharacter(harry);
        gryffindor.addCharacter(hermione);
        gryffindor.addCharacter(ron);
        

        gryffindor.orderCharacters();

        Hogwarts.getInstance().addHouse("Gryffindor", gryffindor);

        
        
        
        
        House hufflepuff = new House("Hufflepuff",false, new OffensiveComparator());

        Character cedric = new DefensiveCharacter("Cedric Diggory", new OffensiveHawthorn("CedricW")); 
        cedric = new InvigorationPotioned(cedric);

        Character nymphadora = new DefensiveCharacter("Nymphadora Tonks", new OffensiveHawthorn("NymphadoraW"));

        Character pomona = new DefensiveCharacter("Pomona Sprout", new OffensiveHawthorn("PomonaW"));
        pomona = new FelixFelicisPotioned(pomona);

        Character rolf = new DefensiveCharacter("Rolf Scamander", new OffensiveHawthorn("RolfW"));

       Character silvanus = new DefensiveCharacter("Silvanus Kettleburn", new OffensiveHawthorn("SilvanusW"));
        silvanus = new FelixFelicisPotioned(silvanus);
        
        Character susan = new DefensiveCharacter("Susan Bones", new OffensiveHawthorn("SusanW"));
       
        Character newton = new DefensiveCharacter("Newton Scammander", new OffensiveHawthorn("RolfW"));
      
        Character hannah = new DefensiveCharacter("Hannah Abbott", new OffensiveHawthorn("RolfW"));
        hannah = new FelixFelicisPotioned(hannah);

        
        
        
        
        
        hufflepuff.addCharacter(cedric);
        hufflepuff.addCharacter(nymphadora);
        hufflepuff.addCharacter(pomona);
        hufflepuff.addCharacter(rolf);
        hufflepuff.addCharacter(silvanus);
        hufflepuff.addCharacter(susan);
        hufflepuff.addCharacter(newton);
        hufflepuff.addCharacter(hannah);        

        hufflepuff.orderCharacters();

        Hogwarts.getInstance().addHouse("Hufflepuff", hufflepuff);

        
        
        
        
        
        
        
        House slytherin = new House("Slytherin", true,new OffensiveComparator());

        Character draco = new DefensiveCharacter("Draco Malfoy", new HollyDefensive("DracoW"));
        draco = new FelixFelicisPotioned(draco);


        slytherin.addCharacter(draco);


        slytherin.orderCharacters();

        Hogwarts.getInstance().addHouse("Slytherin", slytherin);

    }
    
}
