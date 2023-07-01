
/**
 * Abstract class AbstractCharacter - it has the methots that are common for all the subclasses
 * 
 * @author: Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia 
 * Date: 05/12/19 
 */
public abstract class AbstractCharacter implements Character
{
    private String name;
    private double energy;
    private  double offensive;
    private double defensive;
    private Wand wand;

    /**
     *  Parametric constructor of AbstractCharacter
     *  @param String name of the character, double Energy og the character,
     *         double Offensive points of the character, double Deffensive points of the character, 
     *         wand Wand of the character
     *  
     */
    public AbstractCharacter(String name, Wand wand)
    {   

        this.name = name;
        this.energy =20.00;
        this.offensive = 20.00;
        this.defensive = 20.00;
        this.wand = wand;

    }

    /**
     *  Set the name of the Character
     *  @param String name
     *  @return 
     */
    public void setName(String name)
    {

        this.name = name;

    }

    /**
     *  Get the name of the Character
     *  @param 
     *  @return String name of the Character
     */
    public String getName()
    {

        return name;

    }

    /**
     *  Set the energy of the Character
     *  @param String energy
     *  @return 
     */
    public void setEnergy(double energy)
    {

        this.energy = energy;

    }

    /**
     *  Returns the energy of the character
     *  @param 
     *  @return energy of the character
     */
    public double getEnergy()
    {

        return energy;

    }    

    /**
     *  Set the offensivePoints of the Character
     *  @param String offensive
     *  @return 
     */
    public void setOffensive(double offensive)
    {

        this.offensive = offensive; 

    }

    /**
     *  Returns the offensivePoints
     *  @param 
     *  @return energy of the offensivePoints
     */
    public double getOffensive(){

        return offensive; 

    }

    /**
     *  Set the DeffensivePoints of the Character
     *  @param String defensive
     *  @return 
     */
    public void setDefensive(double defensive)
    {

        this.defensive = defensive; 

    }

    /**
     *  Returns the defensivePoints of the character
     *  @param 
     *  @return defensivePoints of the character
     */
    public double getDefensive()
    {

        return defensive; 

    }

    /**
     *  Set the wand of the Character
     *  @param Wand wand
     *  @return 
     */
    public void setWand(Wand wand)
    {

        this.wand=wand;   

    }

    /**
     *  Returns the Wand of the character
     *  @param 
     *  @return wand Wand of the character
     */
    public Wand getWand()
    {

        return wand; 

    }
    
    /**
     *  Returns the name of the wand of the character
     *  @param 
     *  @return wand of the character
     */
    public String getWandName()
    {        
        
        return getWand().getName();
        
    }
    
    /**
     *  Returns the wandType of the character
     *  @param 
     *  @return wandType of the character
     */
    public String getWandType()
    {      
        
        return getWand().getType();
        
    }
    
    /**
     *  Calculate the points of two character fighting
     *  @param Character character's enemy
     *  @return 
     */
    public void fight (Character enemy)
    {        
        if(attack() > enemy.resistance())
        {
            enemy.setEnergy(enemy.getEnergy() - (attack() - enemy.resistance()));
            if(enemy.getEnergy() < 0)
            {
                enemy.setEnergy(0);   
            }
        }
    }  

    /**
     *  Calculate the offensive Points
     *  @param 
     *  @return the offensive Points
     */
    public double attack()
    {

        return getWand().attackPower(getEnergy(), getOffensive());  

    }

    /**
     *  Calculate the defensive Points
     *  @param 
     *  @return the defensive Points
     */
    public double resistance()
    {

        return getWand().resistancePower(getEnergy(), getDefensive());

    }

    /**
     *  It changes the wand of a Character
     *  @param Wand newWand u wanna change
     *  @return 
     */
    public void changeWand(Wand newWand)
    {
        
        setWand(newWand);  
        
    }
}
