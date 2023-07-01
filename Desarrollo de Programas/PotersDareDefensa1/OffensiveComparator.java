
/**
 * Compare the order of the Offensive Points
 * 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */
import java.lang.Comparable;
import java.util.Comparator;
public class OffensiveComparator implements Comparator<Character>
{      
    public int compare(Character c1, Character c2){  
        if(c1.getOffensive()==c2.getOffensive()){
            return c1.getName().compareTo(c2.getName());        
        }
        else{            
            if(c1.getOffensive()<c2.getOffensive()){
                return -1;
            }
            else
                return 1; 
        }        
    }  
}
