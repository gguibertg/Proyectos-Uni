
/**
 * Each character uses a Magic Wand during the duels to generate her attack points as well as her resistance points. The difference
 * between each wand depends on the kind of wood used that produces a different result if they are used in an offensively way or in a defensively way.
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */

public interface Wand
{
    /**
     *  Returns the name of the Wand
     *  @param 
     *  @return String The name of the Wand 
     */
    public String getName();

    /**
     *  Returns the type of the Wand
     *  @param 
     *  @return String The type of the Wand
     */
    public String getType();

    /**
     *  
     *  @param energyPoints A doulble from the energyPoints, offensivePoints A doulble from the offensivePoints
     *  @return double
     */
    public double attackPower(double energyPoints, double offensivePoints);

    /**
     *  
     *  @param energyPoints A doulble from the energyPoints, defensivePoints A doulble from the defensivePoints
     *  @return double
     */
    public double resistancePower(double energyPoints, double defensivePoints);
}

