
/**
 * Abstract class Wand - it has the methots that are common for all the subclasses
 * 
 * @author: Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia 
 * Date: 05/12/19  
 */
public abstract class AbstractWand implements Wand
{

    private String name;
    private String type;

    /**
     * Constructor for objects of class Wand
     */     
    public AbstractWand(String name,String type){

        this.name=name;  
        this.type = type;

    }

    /**
     *  Returns the name of the Wand
     *  @param 
     *  @return String The name of the Wand 
     */
    @Override
    public String getName(){

        return this.name;

    }

    /**
     *  Returns the type of the Wand
     *  @param 
     *  @return String The type of the Wand
     */
    @Override
    public String getType()
    {

        return this.type;   

    }

    /**
     *  
     *  @param energyPoints A doulble from the energyPoints, offensivePoints A doulble from the offensivePoints
     *  @return 0
     */
    @Override
    public double attackPower(double energyPoints, double offensivePoints){

        return 0;

    }

    /**
     *  
     *  @param energyPoints A doulble from the energyPoints, defensivePoints A doulble from the defensivePoints
     *  @return 0
     */
    @Override
    public double resistancePower(double energyPoints, double defensivePoints){

        return 0;

    }
}
