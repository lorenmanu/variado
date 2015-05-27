/** -*-Mode: C++;-*-
  @file SoED.h
  @brief TDA SoED
  
 */

#ifndef __SoED_H__
#define __SoED_H__


#include <iostream>
#include <string>
#include <map>
#include "tree.h"

using namespace std;

/** \class SoED SoED.h

Descripción


Toda la información, ya sean textos, imágenes, o información para la configuración del sistema, se almacena en "ficheros", que a su vez se guardan en directorios. Los ficheros son la estructura empleada por el sistema operativo para almacenar información en un dispositivo físico como un disco duro, un disquete, un CD-ROM. 


En esta práctica implementaremos un simulador para un sistema de archivos, llamado SoED (Sistema operativo Estructuras de Datos). Nuestro sistema será multiusuario, por lo que para gestionarlo necesitaremos de dos partes esenciales, por un lado un gestor de usuarios y por otro un árbol de directorios. 


@todo  Tareas a realizar: El alumno debera implementar la clase SoED, juntos con el codigo de prueba de los distintos
 metodos. 

Ver la documentación de la práctica ( \ref intro_sec)
*/

class SoED {
public:

/** @typedef errorCode
Hace referencia al tipo asociado a los errores que se pueden generar. Los códigos de errorCode son
\li 0. operación correcta
\li 1. camino incorrecto (no existe)
\li 2. un usario no tiene permiso para acceder al camino
\li 3. directorio vacío
*/ 
typedef unsigned int errorCode;

/** @typedef size_type
Hace referencia al tipo asociado al tamaño de los ficheros
*/ 
typedef  unsigned int size_type;

/** @typedef userID
Hace referencia al tipo asociado al nombre del usuario. En principio un string con números y/o caracters
*/ 
typedef string userID;

/** @typedef path 
Hace referencia al un camino completo en el árbol de directorios, que puede hacer referencia a un directorio o archivo concreto. 
\li /home/usario/dir1/fichero.dat si es un nombre de fichero.
\li /home/usuario/dir1/dir11/ si es un nombre de directorio
Como se ha comentado, cuando si consideramos un camino completo tenemos tres alternativas para describirlo. Supongamos que consideramos el usuario "pedro", que se encuentra en  directorio de trabajo "/home/pedro/ED/", las tres alternativas harían referencia al directorio DIR, que se encontraría como subdirectorio de ED
\li dir ="/home/pedro/ED/DIR/"
\li dir ="~/ED/DIR/"
\li dir ="./DIR/"
*/
 typedef string path; //Camino completo 
  
    
 /**
     @brief Constructor primitivo 
    Realiza las siguientes acciones.
-# crea el usuario "root"
-# crea los directorios raíz ("/") y    "/home/", ambos teniendo como propietario al root
-# asigna "/" como  directorio por defecto y directorio actual de root
  */
  SoED();

  /**
    @brief Constructor de copia.
    @param[in] x SoED que se copia
     
  */
  SoED( const SoED & x);
  
   /**
     @brief Lectura de un directorio 

     Se genera el arbol de directorio utilizando un recorrido por nivel.
     Esta método (que se entrega implementado) sólo se utilizará para poder generarnos un directorio de prueba. Se le asignará el  usuario ficticio "def"
  @pre Asume que el SeOD se ha creado con el constructor por defecto. En caso contrario el comportamiento no tiene porque ser el correcto
     */
   void reading_SoED(  );

   /**
     @brief Evalua SoED  NO IMPLEMENTAR
     
     Este es un método que el alumno NO DEBE implementar en el fichero SoED.cpp, ni siquiera incluirlo aunque no haga nada.
     El método se utilizará para poder evaluar los distintos métodos creados por el alumno
     
     */
   int evalua_SoED( const string & s );
/** 
  @brief devuelve el camino completo del directorio de trabajo para el usuario user
@param[in] user Nombre el usuario
*/
path pwd(const userID & user) const;

/** 
  @brief busca una cadena en el árbol de directorios
@param[in] s  cadena a buscar
@param[in] u nombre de usuario

\li Busca la cadena s dentro del subdirectorio del usuario u, si u == root busca la cadena s en todo el directorio.
\li La cadena s debe ser subcadena de un nombre de directorio o de un nombre de archivo.

@return lista de nombres de paths que contienen a s. 
*/
list<path> locate( const userID & u, const string & s) const;

/** 
  @brief Crea un directorio
@param[in] u  nombre de usuario
@param[in] dir  nombre del directoria a crear, debe acabar en /

En dir podemos distinguir dos partes, el camino y en nombre del nuevo directorio ".../camino/nuevoDir/", 
Si existe el camino en árbol de directorios y el usuario tiene acceso al mismo, crea un nuevo directorio 
@return codigo de error
*/
errorCode mkdir(const userID  & u, const path & dir);

/**  @brief Borra un directorio
@param[in] u  nombre de usuario
@param[in] dir  nombre del directoria a borrar, debe acabar en /


En dir podemos distinguir dos partes, el camino y en nombre del  directorio a borrar ".../camino/ DirABorrar/". Si existe el camino en árbol de directorios, y el usuario tiene permisos borra DirABorrar/ siempre que esté vacio

@return codigo de error
*/
errorCode rmdir(const userID & u, const path & dir);


/**  @brief renombra org a dest o mueve org a un directorio
@param[in] u  nombre de usuario
@param[in] org  nombre de la entrada a mover (fichero o directorio)
@param[in] dest  destino de la entrada (fichero o directorio)

Mueve o renombre el directorio/fichero origen al directorio dest. Si el dest se encuentra en el mismo directorio que org, entonces renombra el directorio, si dest se encuentra en otro directorio lo que hace es mover la entrada al directorio destino (eliminándose del directorio origen)

@return codigo de error
*/
errorCode mv(const userID & u, const path & org, const path & dest);

/**  @brief copia una entrada orgien a una destino
@param[in] u  nombre de usuario
@param[in] org  nombre de la entrada a mover (fichero o directorio)
@param[in] dest  destino de la entrada (fichero o directorio)

Copia el directorio/fichero origen al directorio dest. 

@return codigo de error
*/
errorCode cp(const userID & u, const path & org, const path & dest);



/** @brief Cambio de directorio
@param[in] u identificador del usuario
@param[in] d camino
Hace que el usuario cambie al directorio de trabajo representado por d

@return  codigo de error
*/
errorCode cd(const userID & u, const path & d);

/** @brief Cambio de directorio
@param[in] u identificador del usuario

Hace que el usuario cambie a su directorio raíz, en /home/...
*/
void cd(const userID & u);

/** @brief lista las entradas de un directorio
@param[in] u identificador del usuario
lista todas las entradas de un directorio
@return la lista con los nombres de  entradas de un directorio
*/
list<string> ls(const userID & u) const;

/** @brief Crea un fichero enel directorio de trabajo
@param[in] u identificador del usuario
@param[in] s nombre del fichero
@param[in] tama tamaño del fichero
Crea un nuevo fichero con nombre s en el directorio de trabajo con tamaño tama.
En el caso en que exista ya un fichero o directorio con en mismo nombre,
 el fichero no se puede crear.
 El nuevo fichero sera propiedad del usuario u.

 @return codigo de error
*/
errorCode mkFile(const userID & u, const string &s ,size_type  tama);

/** @brief borra un fichero
@param[in] u identificador del usuario
@param[in] p camino del fichero

Borra el fichero indicado por el camino p. Si p=="*", borra todos los ficheros del
directorio de trabajo

@return codigo de error
*/
errorCode rm(const userID & u, const path & p);

/** @brief añade un nuevo usuario al sistema
@param[in] user identificador del usuario
Añade un nuevo usuario, el nombre user no debe existir en el sistema.
Crea el directorio raíz del usuario en /home/user, que es propiedad de dicho usuario

@return Devuelve true si se ha podido realizar la acción, false si ya existe en usuario
*/
bool useradd(const userID & user);

/** @brief borra un usuario del sistema
@param[in] user identificador del usuario
Borra el usuario, y todo su directorio del sistema.
*/
void userdel(const userID & user);

/** @brief lista todos los usuarios del sistem
@return Devuelve una lista con todos los usuarios del sistema
*/
list<userID>  who() const;

/** @brief tamaño ocupado por el sistema
@param[in] u identificador del usuario
@param[in] p camino a un directorio

Devuelve el numero de K ocupadas por todos los ficheros que se encuentran a partir de un
 directorio p. El directorio p debe ser propiedad del usuario u (excepto para root, que tiene acceso
 a todo el sistema)

 @return Devuelve un par donde el primer campo representa el tamaño y segundo campo representa si se ha podido realizar la acción (codgio de error)

*/
pair<size_type,errorCode> du(const userID & u, const path& p) const;

/** @brief tamaño ocupado por el sistema
@param[in] u identificador del usuario

@return Devuelve el numero de K ocupadas por todos los ficheros propiedad del usuario u
*/
size_type du(const userID &u) const;

/** @brief lista de todos los directorios del sistema
@param[in] u identificador del usuario
@param[in] p camino a un directorio

@return Devuelve la lista de caminos completos hacia todos los archivos/directorios que cuelgan de p. En caso de error, u no tiene acceso a p, o p es un camino erroneo devuelve la lista vacía.
*/
list<path> treeList(const userID &u, const path & p) const;


/** @brief lista de todos los directorios del sistema
@param[in] u identificador del usuario

@return Devuelve la lista de caminos completos de todos los archivos/directorios que cuelgan de p.
*/
list<path> treeList(const userID &u) const;


 
 
 
 
private:
   struct entrada{
   string nombre; //nombre fichero/directorio
   size_type tama; //tama del fichero
   userID propietario;
   } ;

 
 tree< entrada > arbol; 
 map<string, pair< tree<entrada>::node, tree<entrada>::node >  > users; 
//users["jhg"].first hace referencia al directorio por defecto
//users["jhg"].second hace referencia al directorio actual.
 

/** @brief Define el Invariante de la Representacion. 
@todo Chequea el invariante de la representación

*/
  bool cheq_rep();
};

#endif

