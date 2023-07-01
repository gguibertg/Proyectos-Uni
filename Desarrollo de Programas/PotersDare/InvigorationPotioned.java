
/**
 * Write a description of class InvigorationPotion here.
 * 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */
public class InvigorationPotioned extends AbstractPotion
{
    /**
     * Constructor for objects of class InvigorationPotion
     */
    public InvigorationPotioned(Character character)
    {
        
      super(character);
      
    }
    
    /**
     *  Returns the defensivePoints after use the potion
     *  @param 
     *  @return double The defensivePoints after use the potion
     */
    public double getDefensive()
    {
        
     return getDecorated().getDefensive() * 1.4;
     
    }
}
