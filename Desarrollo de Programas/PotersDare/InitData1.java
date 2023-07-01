
/**
 * Class to init data of the simulation. 
 * It could be used alto to write finals results.
 * 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version 19/20
 */
import java.util.*;
public class InitData1
{
    public InitData1()
    {
        initData1();
    }

    private void initData1()
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

        House gryffindor = new House("Gryffindor",false, new DefensiveComparator());

        Character harry = new OffensiveCharacter("Harry Potter",new OffensiveHawthorn("HarryW"));
        harry = new InvigorationPotioned(harry); 
        harry = new FelixFelicisPotioned(harry);

        Character hermione = new DefensiveCharacter("Hermione Granger", new HollyDefensive("HermioneW")); 
        hermione = new InvigorationPotioned(hermione);

        Character ron = new DefensiveCharacter("Ron Weasley", new OffensiveHawthorn("RonW"));
        ron = new FelixFelicisPotioned(ron); 

        Character neville = new DefensiveCharacter("Neville Longbottom", new OffensiveHawthorn("NevilleW"));

        gryffindor.addCharacter(harry);
        gryffindor.addCharacter(hermione);
        gryffindor.addCharacter(ron);
        gryffindor.addCharacter(neville);

        gryffindor.orderCharacters();

        Hogwarts.getInstance().addHouse("Gryffindor", gryffindor);

        House hufflepuff = new House("Hufflepuff",false, new OffensiveComparator());

        Character cedric = new DefensiveCharacter("Cedric Diggory", new OffensiveHawthorn("CedricW")); 
        cedric = new InvigorationPotioned(cedric);

        Character nymphadora = new DefensiveCharacter("Nymphadora Tonks", new OffensiveHawthorn("NymphadoraW"));

        Character pomona = new OffensiveCharacter("Pomona Sprout", new OffensiveHawthorn("PomonaW"));
        pomona = new FelixFelicisPotioned(pomona);

        Character rolf = new DefensiveCharacter("Rolf Scamander", new OffensiveHawthorn("RolfW"));

        hufflepuff.addCharacter(cedric);
        hufflepuff.addCharacter(nymphadora);
        hufflepuff.addCharacter(pomona);
        hufflepuff.addCharacter(rolf);

        hufflepuff.orderCharacters();

        Hogwarts.getInstance().addHouse("Hufflepuff", hufflepuff);

        House slytherin = new House("Slytherin", true,new OffensiveComparator());

        Character draco = new DefensiveCharacter("Draco Malfoy", new HollyDefensive("DracoW"));

        Character dolores = new OffensiveCharacter("Dolores Umbridge", new HollyDefensive("DoloresW"));

        Character pansy = new OffensiveCharacter("Pansy Parkinson", new OffensiveHawthorn("PansyW"));
        pansy = new FelixFelicisPotioned(pansy);

        Character albus = new OffensiveCharacter("Albus Severus Potter", new HollyDefensive("AlbusW"));

        slytherin.addCharacter(draco);
        slytherin.addCharacter(dolores);
        slytherin.addCharacter(pansy);
        slytherin.addCharacter(albus);

        slytherin.orderCharacters();

        Hogwarts.getInstance().addHouse("Slytherin", slytherin);

    }

   
   
}
