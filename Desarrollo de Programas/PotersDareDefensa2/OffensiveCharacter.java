
/**
 * Write a description of class OffensiveCharacter here.
 * 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */
public class OffensiveCharacter extends AbstractCharacter 
{    
    /**
     * Constructor for objects of class OffensiveCharacter
     */
    private static final int extraOffense=5;
    public OffensiveCharacter(String name, Wand wand)
    {

        super(name, wand);
        setOffensive(this.getDefensive()+extraOffense);

    }    
}
