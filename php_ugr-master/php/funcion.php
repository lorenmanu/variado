<?php
    function aniadir_pie2($servicio,$dirCElectronico)
        {
            $cadena= ' <footer> <img src="escudo_ugr.jpg" width="100%" height="7" />
            <address> <p>'. $servicio.' Universidad de Granada</p>
            <br />Cuesta del Hospicio, s/n
            <br />Granada, 18071
            </address>
            <p>Contacto: <a href="mailto:'.$dirCElectronico.'">UGR </a> </p> </footer>';
            return $cadena;
        }
?>
