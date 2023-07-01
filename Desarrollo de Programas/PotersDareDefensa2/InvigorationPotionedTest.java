

import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class InvigorationPotionedTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class InvigorationPotionedTest
{
    private HollyDefensive defensiveWand;
    private OffensiveCharacter rafael;
    private InvigorationPotioned invigorationPotionedRafael;

    /**
     * Default constructor for test class InvigorationPotionedTest
     */
    public InvigorationPotionedTest()
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
        defensiveWand = new HollyDefensive("RafaelW");
        rafael = new OffensiveCharacter("Rafael", defensiveWand);
        invigorationPotionedRafael = new InvigorationPotioned(rafael);
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
    public void getDefensiveTest()
    {
        assertEquals(28, invigorationPotionedRafael.getDefensive(), 0.1);
    }
}

