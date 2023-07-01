

import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class FelixFelicisPotionedTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class FelixFelicisPotionedTest
{
    private OffensiveHawthorn offensiveWand;
    private DefensiveCharacter gabriel;
    private FelixFelicisPotioned gabrielFelixFelicisPotioned;

    /**
     * Default constructor for test class FelixFelicisPotionedTest
     */
    public FelixFelicisPotionedTest()
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
        offensiveWand = new OffensiveHawthorn("GabrielW");
        gabriel = new DefensiveCharacter("Gabriel", offensiveWand);
        gabrielFelixFelicisPotioned = new FelixFelicisPotioned(gabriel);
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
    public void getOffensiveTest()
    {
        assertEquals(26, gabrielFelixFelicisPotioned.getOffensive(), 0.1);
    }
}



