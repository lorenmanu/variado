<?php
    interface MiInterfaz {
        public function metodo1( $param1, $param2 );
        public function metodo2( $param1, $param2 );
    }
    class MiClase implements MiInterfaz {
        public function metodo1( $param1, $param2 ) {
                  // (implementación del método.)
        }
        public function metodo2( $param1, $param2 ) {
                // (implementación del método.)
        }
    }
?>
