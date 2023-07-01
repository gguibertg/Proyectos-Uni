

import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class HollyDefensiveTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class HollyDefensiveTest
{
    private HollyDefensive defensiveWand;

    /**
     * Default constructor for test class HollyDefensiveTest
     */
    public HollyDefensiveTest()
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
        defensiveWand = new HollyDefensive("GabriW");
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
        assertEquals("GabriW", defensiveWand.getName());
    }

    @Test
    public void getTypeTest()
    {
        assertEquals("HollyDefensive", defensiveWand.getType());
    }

    @Test
    public void attackPowerTest()
    {
        assertEquals(21.86, defensiveWand.attackPower(17.3, 32.5), 0.1);
    }

    @Test
    public void resistancePowerTest()
    {
        assertEquals(37.57, defensiveWand.resistancePower(17.3, 20), 0.1);
    }
}




