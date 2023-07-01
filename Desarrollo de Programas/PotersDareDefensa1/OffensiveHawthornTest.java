
import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class OffensiveHawthornTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class OffensiveHawthornTest
{
    private OffensiveHawthorn offensiveWand;

    /**
     * Default constructor for test class OffensiveHawthornTest
     */
    public OffensiveHawthornTest()
    {
    }

    /**
     * Sets up the test fixture.
     *
     * Called before every test case method.
     */
    @Before
    public void setUp()
    {
        offensiveWand = new OffensiveHawthorn("CarlosW");
    }

    /**
     * Tears down the test fixture.
     *
     * Called after every test case method.
     */
    @After
    public void tearDown()
    {
    }

    @Test
    public void getNameTest()
    {
        assertEquals("CarlosW", offensiveWand.getName());
    }

    @Test
    public void getTypeTest()
    {
        assertEquals("OffensiveHawthorn", offensiveWand.getType());
    }

    @Test
    public void attackPowerTest()
    {
        assertEquals(38.42, offensiveWand.attackPower(19, 19.3), 0.1);
    }

    @Test
    public void resistancePowerTest()
    {
        assertEquals(26.32, offensiveWand.resistancePower(19, 55.6), 0.1);
    }
}





