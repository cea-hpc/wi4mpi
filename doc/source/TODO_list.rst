Todo list
*********

pour info et pour que ce soit mis dans la doc j'ai généralisé une pratique sur les fonctions non  implementées, je génére une implementation pour les fonctions  qui sont en execptions et qui n'ont pas de fichier d'implementation manuelle qui fait :

un message d'erreur explicite disant que l'implemation n'est pas faite
un appel à MPI_Abort pour quitter proprement

a materialisation c'est : 
dans execptions.json (lib/etc/code/common/json/exceptions.json), 

..code-block:: json
    "MPI_Pcontrol": {
       "Application": {
         "C": {
           "generated": "False",
           "file": "A_MPI_Pcontrol.c"
         },
         "fortran": {
           "generated": "False"
         }
       },

En C on aura le code contenu dans le fichier lib/etc/code/C/static_sources/A_MPI_Pcontrol.c  et en fortran il y aura le code généré suivant :

.. code-block:: C
    void A_f_MPI_Pcontrol(int *level,int *ier)
    {
       fprintf(stderr,"MPI_Pcontrol in not implemented yet in fortran");
    R_MPI_Abort(R_MPI_COMM_WORLD,255);
    }

.. todolist::
