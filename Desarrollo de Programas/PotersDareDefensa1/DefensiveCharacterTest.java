

import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class DefensiveCharacterTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class DefensiveCharacterTest
{
    private HollyDefensive defensiveWand;
    private OffensiveHawthorn offensiveWand;
    private DefensiveCharacter rafael;
    private DefensiveCharacter enemy;
    
    /**
     * Default constructor for test class DefensiveCharacterTest
     */
    public DefensiveCharacterTest()
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
        offensiveWand = new OffensiveHawthorn("ElderW");
        rafael = new DefensiveCharacter("Rafa", defensiveWand);
        enemy = new DefensiveCharacter("Antonio", offensiveWand);
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
        rafael.setName("Rafael");
        assertEquals("Rafael", rafael.getName());
    }

    @Test
    public void getNameTest()
    {
        assertEquals("Rafa", rafael.getName());
    }

    @Test
    public void setEnergyTest()
    {
        rafael.setEnergy(42.00);
        assertEquals(42.0, rafael.getEnergy(), 0.1);
    }

    @Test
    public void getEnergyTest()
    {
        assertEquals(20, rafael.getEnergy(), 0.1);
    }

    @Test
    public void setOffensiveTest()
    {
        rafael.setOffensive(24.4);
        assertEquals(24.4, rafael.getOffensive(), 0.1);
    }

    @Test
    public void getOffensiveTest()
    {
        assertEquals(20, rafael.getOffensive(), 0.1);
    }

    @Test
    public void setDefensiveTest()
    {
        rafael.setDefensive(57.1);
        assertEquals(57.1, rafael.getDefensive(), 0.1);
    }

    @Test
    public void getDefensiveTest()
    {
        assertEquals(25.0, rafael.getDefensive(), 0.1);
    }

    @Test
    public void setWandTest()
    {
        rafael.setWand(offensiveWand);
        assertEquals(offensiveWand, rafael.getWand());
    }

    @Test
    public void getWandTest()
    {
        assertEquals(defensiveWand, rafael.getWand());
    }

    @Test
    public void getWandNameTest()
    {
        assertEquals("RafaelW", rafael.getWandName());
    }

    @Test
    public void getWandTypeTest()
    {
        assertEquals("HollyDefensive", rafael.getWandType());
    }

    @Test
    public void attackTest()
    {
        assertEquals(20, rafael.attack(), 0.1);
    }

    @Test
    public void fightTest()
    {
        enemy.setDefensive(5);
        rafael.fight(enemy);
        assertEquals(17, enemy.getEnergy(), 0.1);
    }

    @Test
    public void changeWandTest()
    {
        rafael.changeWand(offensiveWand);
        assertEquals(offensiveWand, rafael.getWand());
    }
}





















