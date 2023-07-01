

import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class HouseTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class HouseTest
{
    private House ravenclaw;
    private OffensiveHawthorn offensiveWand;
    private DefensiveCharacter rafael;
    private HollyDefensive deffensiveWand;
    private OffensiveHawthorn theCoolestWand;
    private OffensiveCharacter carlos;
    private OffensiveCharacter gabri;

    /**
     * Default constructor for test class HouseTest
     */
    public HouseTest()
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
        ravenclaw = new House("Ravenclaw", false, new DefensiveComparator());
        offensiveWand = new OffensiveHawthorn("RafaW");
        rafael = new DefensiveCharacter("Rafael", offensiveWand);
        deffensiveWand = new HollyDefensive("CarlosW");
        theCoolestWand = new OffensiveHawthorn("GabriW");
        carlos = new OffensiveCharacter("Carlos", deffensiveWand);
        gabri = new OffensiveCharacter("Gabri", theCoolestWand);
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
    public void setNameTest()
    {
        ravenclaw.setName("LaCasaOlvidada");
        assertEquals("LaCasaOlvidada", ravenclaw.getName());
    }

    @Test
    public void getNameTest()
    {
        assertEquals("Ravenclaw", ravenclaw.getName());
    }



    @Test
    public void nCharTest()
    {
        ravenclaw.addCharacter(rafael);
        ravenclaw.addCharacter(carlos);
        assertEquals(2, ravenclaw.nChar());
    }

    @Test
    public void getTotalEnergyTest()
    {
        ravenclaw.addCharacter(gabri);
        ravenclaw.addCharacter(rafael);
        assertEquals(40, ravenclaw.getTotalEnergy(), 0.1);
    }

    @Test
    public void getFirstTest()
    {
        ravenclaw.addCharacter(gabri);
        ravenclaw.addCharacter(carlos);
        ravenclaw.addCharacter(rafael);
        assertEquals(gabri, ravenclaw.first());
    }

    @Test
    public void removeFirstTest()
    {
        ravenclaw.addCharacter(gabri);
        ravenclaw.addCharacter(rafael);
        ravenclaw.addCharacter(carlos);
        ravenclaw.removeFirst();
        assertEquals(rafael, ravenclaw.first());
    }

    @Test
    public void getTotalPointsTest()
    {
        ravenclaw.addCharacter(rafael);
        ravenclaw.addCharacter(gabri);
        ravenclaw.addCharacter(carlos);
        assertEquals(135.0, ravenclaw.getTotalPoints(), 0.1);
    }


}













