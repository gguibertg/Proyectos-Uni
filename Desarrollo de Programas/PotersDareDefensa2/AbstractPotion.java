/**
 *Any character could drink different extra potions along the competition. 
 *These potions increase the offensive points and/or the defensive points of the characters who drink them. 
 *A character could not use ever one of these potions, use one of them, use two of them or even use all of them during the same competition. 
 * 
 * @author: Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia 
 * Date: 05/12/19 
 */
public abstract class AbstractPotion extends AbstractCharacter
{
    private Character decoratedCharacter;  

    /**
     * 
     */
    public AbstractPotion(Character character)
    {

        super(character.getName(), character.getWand());    
        decoratedCharacter = character; 

    } 

    /**
     *  Decorate the character class
     *  @param 
     *  @return double OffensivePoints changed by the potion
     */
    public double getOffensive()
    {

        return decoratedCharacter.getOffensive(); 

    }

    /**
     *  Decorate the character class
     *  @param 
     *  @return double DeffensivePoints changed by the potion
     */
    public double getDefensive()
    {

        return decoratedCharacter.getDefensive(); 

    }

    /**
     *  Returns the character decorated
     *  @param 
     *  @return Character Returns the decoratedCharacter
     */
    public Character getDecorated()
    {

        return decoratedCharacter;  

    }
}
