
/**
 * Write a description of class OffensiveHawthorn here.
 * 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */
public class OffensiveHawthorn extends AbstractWand 
{
    /**
     * Constructor for objects of class OffensiveHawthorn
     */
    public OffensiveHawthorn(String name)
    {
        
        super(name, "OffensiveHawthorn");

    }
    
    /**
     * Returns attackPower of the Wand 
     *  @param energyPoints The energy of the Wand, offensivePoints The points of the offensive Wand
     *  @return double The attackPower of the Wand
     */
    @Override
    public double attackPower(double energyPoints, double offensivePoints){ 
        
        return 0.6 * energyPoints + 1.4 * offensivePoints;
        
    }

    /**
     * Returns resistancePower of the Wand 
     *  @param energyPoints The energy of the Wand, defensivePoints The points of the offensive Wand
     *  @return double The resistancePower of the Wand
     */
    @Override
    public double resistancePower(double energyPoints, double defensivePoints){
        
        return 0.8* energyPoints + 0.2 * defensivePoints;
        
    }
}
