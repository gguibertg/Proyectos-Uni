
/**
 * Write a description of class PolyJuicePotioned here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class PolyJuicePotioned extends AbstractPotion
{

    /**
     * Constructor for objects of class PolyJuicePotioned
     */
    public PolyJuicePotioned(Character character)
    {
        super(character);
    }
    
    public double getOffensive(){

        return getDecorated().getOffensive() * 100;

    }
    
    public double getEnergy(){
        
        return -1.00;
        
    }
}
