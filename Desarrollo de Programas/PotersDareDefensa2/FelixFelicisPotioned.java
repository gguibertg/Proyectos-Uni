
/**
 * Write a description of class InvigorationPotion here.
 * 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */
public class FelixFelicisPotioned extends AbstractPotion
{

    /**
     * Constructor for objects of class InvigorationPotion
     */
    public FelixFelicisPotioned(Character character)
    {

        super(character);

    }  

    /**
     *  Returns the offensivePoints after use the potion
     *  @param 
     *  @return double The offensivePoints after use the potion
     */
    public double getOffensive(){

        return getDecorated().getOffensive() * 1.3;

    }
}
