
/**
 * Write a description of class DefensiveCharacter here.
 * 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */
public class DefensiveCharacter extends AbstractCharacter
{   
    /**
     * Constructor for objects of class DefensiveCharacter
     */
    private static final int extraDefense=5;
    public DefensiveCharacter(String name, Wand wand)
    { 

        super(name, wand);
        setDefensive(this.getDefensive()+extraDefense);

    }
}
