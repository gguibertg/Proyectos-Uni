
/**
 * Class to init data of the simulation. 
 * It could be used alto to write finals results.
 * 
 *@author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version 19/20
 */
import java.util.*;
public class InitData
{
    public InitData()
    {
        initData();
    }

    private void initData()
    {
        //New wands
        //-----------------------
        Hogwarts.getInstance().addWand(new HollyDefensive("Larch"));
        Hogwarts.getInstance().addWand(new HollyDefensive("Rowan"));
        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Hazel"));
        Hogwarts.getInstance().addWand(new HollyDefensive("Tamarack"));
        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Spruce"));
        Hogwarts.getInstance().addWand(new OffensiveHawthorn("Laurel"));
        
        
        
        //Griffindor's characters
        //-----------------------------
        House gryffindor = new House("Gryffindor",false, new DefensiveComparator());
        Character harry = new DefensiveCharacter("Harry Potter",new HollyDefensive("HarryW"));
        harry= new InvigorationPotioned(harry);
            //->assign  InvigorationPotion to harry 
        Character hermione = new OffensiveCharacter("Hermione Granger",new OffensiveHawthorn("HermioneW"));
        hermione= new InvigorationPotioned(hermione);
        //->assign  InvigorationPotion to hermione 
        Character ron = new DefensiveCharacter("Ron Weasley",new OffensiveHawthorn("RonW"));
        ron=new FelixFelicisPotioned(ron);
        //->assign  FelixFelicisPotion to ron 
        Character neville = new OffensiveCharacter("Neville Longbottom",new HollyDefensive("NevilleW"));
        gryffindor.addCharacter(harry);
        gryffindor.addCharacter(hermione);
        gryffindor.addCharacter(ron);
        gryffindor.addCharacter(neville);
        // ->sort gryffindor’s members
        gryffindor.orderCharacters();
        Hogwarts.getInstance().addHouse("Gryffindor", gryffindor);

        //Hufflepuff's characters
        //------------------------------
        House hufflepuff = new House("Hufflepuff",false, new OffensiveComparator());
        Character cedric = new OffensiveCharacter("Cedric Diggory",new HollyDefensive("CedricW"));
        cedric=new FelixFelicisPotioned(cedric);
        //->assign  FelixFelicisPotion to cedric
        Character nymphadora = new DefensiveCharacter("Nymphadora Tonks",new HollyDefensive("NymphadoraW"));
        Character pomona = new OffensiveCharacter("Pomona Sprout",new HollyDefensive("PomonaW"));
        pomona=new FelixFelicisPotioned(pomona);
        //->assign  FelixFelicisPotion to pomona
        Character rolf = new DefensiveCharacter("Rolf Scamander",new OffensiveHawthorn("RolfW"));
        hufflepuff.addCharacter(cedric);
        hufflepuff.addCharacter(nymphadora);
        hufflepuff.addCharacter(pomona);
        hufflepuff.addCharacter(rolf);
        //->sort hufflepuff’s members
        hufflepuff.orderCharacters();
        Hogwarts.getInstance().addHouse("Hufflepuff",hufflepuff);

        //Slytherin's characters
        //----------------------
        House slytherin = new House("Slytherin",true, new OffensiveComparator());
        Character draco = new OffensiveCharacter("Draco Malfoy",new OffensiveHawthorn("DracoW"));
        draco=new FelixFelicisPotioned(draco);
        //->assign  FelixFelicisPotion to draco
        Character dolores = new DefensiveCharacter("Dolores Umbridge",new HollyDefensive("DoloresW"));
        Character pansy = new OffensiveCharacter("Pansy Parkinson",new OffensiveHawthorn("PansyW"));
        pansy=new FelixFelicisPotioned(pansy);
        //->assign  FelixFelicisPotion to pansy
        Character albus = new DefensiveCharacter("Albus Severus Potter",new HollyDefensive("AlbusW"));
        slytherin.addCharacter(draco);
        slytherin.addCharacter(dolores);
        slytherin.addCharacter(pansy);
        slytherin.addCharacter(albus);
        //->sort slytherin’s members
        slytherin.orderCharacters();
        Hogwarts.getInstance().addHouse("Slytherin",slytherin);
    }

}

