
import java.util.Comparator;
import java.lang.Comparable;

/**
 * Compare the order of the Energy Points
 * 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */
public class EnergyComparator implements Comparator<Character>
{
    public int compare(Character c1, Character c2){
        if(c1.getEnergy()==c2.getEnergy()){
            return c1.getName().compareTo(c2.getName());        
        }
        else{            
            if(c1.getEnergy()>c2.getEnergy()){
                return 1;
            }
            else
                return -1;          
        }

    } 
}
