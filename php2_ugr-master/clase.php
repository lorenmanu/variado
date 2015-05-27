class Coche
{
    /* Lista de atributos */
    private $color= "negro"; /* Asignación de un valor por defecto. */
    const NUMRUEDAS=4;
    private $combustible;
    private $puertas=array("delanteras","traseras");
    static public $numeroCoches=0;

    /* Lista de métodos */
    /* Constructor */
    function __construct($color)
    {
        Coche::$numeroCoches++;
        $this­>combustible=60;
        $this­>color=$color;
    }

    /* Destructor */
    function __destruct()
    {   
         echo "Hasta luego, Lucas";
         Coche::$numeroCoches­­; 
    }

    private function echarGasofa($cantidad)
    {
         $this­>combustible=$this­>combustible+$cantidad;
    }
    public function ponerCombustible ($cantidad)
    {
        echarGasofa($cantidad);
    }
    public function consumirCombustible ($cantidad)
    {
        $this­>combustible=$this­>combustible­$cantidad;
        try
        {
            if ($this­>combustible < 0)
            { 
                throw new Exception( "Se ha quedado sin gasofa."); }
            }
        catch (Exception $e)
        {
            echo $e­>getMessage();
            echo "\n<br />\n";
            exit();
         }
    }
    public static function calcularAutonomia()
    {
     /* Código */
    }
}
