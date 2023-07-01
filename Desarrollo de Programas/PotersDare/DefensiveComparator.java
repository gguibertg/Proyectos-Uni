
import java.lang.Comparable;
import java.util.Comparator;

/**
 * Compare the order of the Deffensive Points
 * 
 * @author (Rafael Canito Rubio, Carlos Garcia Garay, Gabriel Fernando Guiberteau Garcia) 
 * @version (05/12/19)
 */
public class DefensiveComparator implements Comparator<Character>
{
    public int compare(Character c1, Character c2){
        if(c1.getDefensive()==c2.getDefensive()){
            return c1.getName().compareTo(c2.getName());        }
        else{            
            if(c1.getDefensive()>c2.getDefensive()){
                return 1;
            }
            else
                return -1;          
        }
    }
}

