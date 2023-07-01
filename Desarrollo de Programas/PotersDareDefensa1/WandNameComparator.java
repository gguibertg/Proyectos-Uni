
import java.util.Comparator;
import java.lang.Comparable;

/**
 * Compare the string names of the wands alphabetically.
 * 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */
public class WandNameComparator implements Comparator <Wand>
{
    public int compare (Wand w1, Wand w2){
        
        return w1.getName().compareTo(w2.getName());  
        
        
        } 
}
