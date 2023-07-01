
/**
 * This class defines the common features of the characters of the simulation that are explained below. 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */

public interface Character
{
    /**
     *  Set the name of the Character
     *  @param String name
     *  @return 
     */
    public void setName(String name);

    /**
     *  Get the name of the Character
     *  @param 
     *  @return String name of the Character
     */
    public String getName();
    
     /**
     *  Set the energy of the Character
     *  @param String energy
     *  @return 
     */
    public void setEnergy(double energy);
    
   /**
     *  Returns the energy of the character
     *  @param 
     *  @return energy of the character
     */
    public double getEnergy();
    
    /**
     *  Set the offensivePoints of the Character
     *  @param String offensive
     *  @return 
     */
    public void setOffensive(double attack);
    
    /**
     *  Returns the offensivePoints
     *  @param 
     *  @return energy of the offensivePoints
     */
    public double getOffensive();
    
    /**
     *  Set the DeffensivePoints of the Character
     *  @param String defensive
     *  @return 
     */
    public void setDefensive(double defensive);
    
    /**
     *  Returns the defensivePoints of the character
     *  @param 
     *  @return defensivePoints of the character
     */
    public double getDefensive(); 
    
    /**
     *  Set the wand of the Character
     *  @param Wand wand
     *  @return 
     */
    public void setWand(Wand wand);
    
    /**
     *  Returns the Wand of the character
     *  @param 
     *  @return wand Wand of the character
     */
    public Wand getWand();
    
    /**
     *  Returns the name of the wand of the character
     *  @param 
     *  @return wand of the character
     */
    public String getWandName();
    
    /**
     *  Returns the wandType of the character
     *  @param 
     *  @return wandType of the character
     */
    public String getWandType();
    
    /**
     *  Calculate the points of two character fighting
     *  @param Character character's enemy
     *  @return 
     */
    public void fight (Character enemy);
    
    /**
     *  Calculate the offensive Points
     *  @param 
     *  @return the offensive Points
     */
    public double attack();
    
    /**
     *  Calculate the defensive Points
     *  @param 
     *  @return the defensive Points
     */
    public double resistance(); 
    
    /**
     *  It changes the wand of a Character
     *  @param Wand newWand u wanna change
     *  @return 
     */
    public void changeWand(Wand newWand);
}
