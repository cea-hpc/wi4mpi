//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique         #
//#                                                                      #
//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
//# This file is part of the Wi4MPI library.                             #
//#                                                                      #
//# This software is governed by the CeCILL-C license under French law   #
//# and abiding by the rules of distribution of free software. You can   #
//# use, modify and/ or redistribute the software under the terms of     #
//# the CeCILL-C license as circulated by CEA, CNRS and INRIA at the     #
//# following URL http://www.cecill.info.                                #
//#                                                                      #
//# The fact that you are presently reading this means that you have     #
//# had knowledge of the CeCILL-C license and that you accept its        #
//# terms.                                                               #
//#                                                                      #
//# Authors:                                                             #
//#   - Delforge Tony <tony.delforge.tgcc@cea.fr>                        #
//#   - Ducrot Vincent <vincent.ducrot.tgcc@cea.fr>                      #
//#                                                                      #
//########################################################################
#ifndef __A_C2FF2C__h__
#define __A_C2FF2C__h__
#include "mappers.h"
#include "manual_wrapper.h"
A_MPI_Comm A_MPI_Comm_f2c(int  op){
if(A_f_MPI_COMM_WORLD==op){return A_MPI_COMM_WORLD;}
if(A_f_MPI_COMM_SELF==op){return A_MPI_COMM_SELF;}
if(A_f_MPI_COMM_NULL==op){return A_MPI_COMM_NULL;}
return (A_MPI_Comm)(op);
}
int  A_MPI_Comm_c2f(A_MPI_Comm op){
if(A_MPI_COMM_WORLD==op){return A_f_MPI_COMM_WORLD;}
if(A_MPI_COMM_SELF==op){return A_f_MPI_COMM_SELF;}
if(A_MPI_COMM_NULL==op){return A_f_MPI_COMM_NULL;}
return (int )(op);
}
A_MPI_Datatype A_MPI_Type_f2c(int  op){
if(A_f_MPI_INTEGER==op){return A_MPI_INTEGER;}
if(A_f_MPI_REAL==op){return A_MPI_REAL;}
if(A_f_MPI_DOUBLE_PRECISION==op){return A_MPI_DOUBLE_PRECISION;}
if(A_f_MPI_COMPLEX==op){return A_MPI_COMPLEX;}
if(A_f_MPI_LOGICAL==op){return A_MPI_LOGICAL;}
if(A_f_MPI_CHARACTER==op){return A_MPI_CHARACTER;}
if(A_f_MPI_BYTE==op){return A_MPI_BYTE;}
if(A_f_MPI_PACKED==op){return A_MPI_PACKED;}
if(A_f_MPI_2REAL==op){return A_MPI_2REAL;}
if(A_f_MPI_2DOUBLE_PRECISION==op){return A_MPI_2DOUBLE_PRECISION;}
if(A_f_MPI_2INTEGER==op){return A_MPI_2INTEGER;}
if(A_f_MPI_DOUBLE_COMPLEX==op){return A_MPI_DOUBLE_COMPLEX;}
if(A_f_MPI_INTEGER1==op){return A_MPI_INTEGER1;}
if(A_f_MPI_INTEGER2==op){return A_MPI_INTEGER2;}
if(A_f_MPI_INTEGER4==op){return A_MPI_INTEGER4;}
if(A_f_MPI_REAL4==op){return A_MPI_REAL4;}
if(A_f_MPI_REAL8==op){return A_MPI_REAL8;}
if(A_f_MPI_UB==op){return A_MPI_UB;}
if(A_f_MPI_LB==op){return A_MPI_LB;}
if(A_f_MPI_DATATYPE_NULL==op){return A_MPI_DATATYPE_NULL;}
return (A_MPI_Datatype)(op);
}
int  A_MPI_Type_c2f(A_MPI_Datatype op){
if(A_MPI_INTEGER==op){return A_f_MPI_INTEGER;}
if(A_MPI_REAL==op){return A_f_MPI_REAL;}
if(A_MPI_DOUBLE_PRECISION==op){return A_f_MPI_DOUBLE_PRECISION;}
if(A_MPI_COMPLEX==op){return A_f_MPI_COMPLEX;}
if(A_MPI_LOGICAL==op){return A_f_MPI_LOGICAL;}
if(A_MPI_CHARACTER==op){return A_f_MPI_CHARACTER;}
if(A_MPI_BYTE==op){return A_f_MPI_BYTE;}
if(A_MPI_PACKED==op){return A_f_MPI_PACKED;}
if(A_MPI_2REAL==op){return A_f_MPI_2REAL;}
if(A_MPI_2DOUBLE_PRECISION==op){return A_f_MPI_2DOUBLE_PRECISION;}
if(A_MPI_2INTEGER==op){return A_f_MPI_2INTEGER;}
if(A_MPI_DOUBLE_COMPLEX==op){return A_f_MPI_DOUBLE_COMPLEX;}
if(A_MPI_INTEGER1==op){return A_f_MPI_INTEGER1;}
if(A_MPI_INTEGER2==op){return A_f_MPI_INTEGER2;}
if(A_MPI_INTEGER4==op){return A_f_MPI_INTEGER4;}
if(A_MPI_REAL4==op){return A_f_MPI_REAL4;}
if(A_MPI_REAL8==op){return A_f_MPI_REAL8;}
if(A_MPI_UB==op){return A_f_MPI_UB;}
if(A_MPI_LB==op){return A_f_MPI_LB;}
if(A_MPI_DATATYPE_NULL==op){return A_f_MPI_DATATYPE_NULL;}
return (int )(op);
}
A_MPI_Op A_MPI_Op_f2c(int  op){
if(A_f_MPI_MAX==op){return A_MPI_MAX;}
if(A_f_MPI_MIN==op){return A_MPI_MIN;}
if(A_f_MPI_SUM==op){return A_MPI_SUM;}
if(A_f_MPI_PROD==op){return A_MPI_PROD;}
if(A_f_MPI_MAXLOC==op){return A_MPI_MAXLOC;}
if(A_f_MPI_MINLOC==op){return A_MPI_MINLOC;}
if(A_f_MPI_BAND==op){return A_MPI_BAND;}
if(A_f_MPI_BOR==op){return A_MPI_BOR;}
if(A_f_MPI_BXOR==op){return A_MPI_BXOR;}
if(A_f_MPI_LAND==op){return A_MPI_LAND;}
if(A_f_MPI_LOR==op){return A_MPI_LOR;}
if(A_f_MPI_LXOR==op){return A_MPI_LXOR;}
if(A_f_MPI_OP_NULL==op){return A_MPI_OP_NULL;}
return (A_MPI_Op)(op);
}
int  A_MPI_Op_c2f(A_MPI_Op op){
if(A_MPI_MAX==op){return A_f_MPI_MAX;}
if(A_MPI_MIN==op){return A_f_MPI_MIN;}
if(A_MPI_SUM==op){return A_f_MPI_SUM;}
if(A_MPI_PROD==op){return A_f_MPI_PROD;}
if(A_MPI_MAXLOC==op){return A_f_MPI_MAXLOC;}
if(A_MPI_MINLOC==op){return A_f_MPI_MINLOC;}
if(A_MPI_BAND==op){return A_f_MPI_BAND;}
if(A_MPI_BOR==op){return A_f_MPI_BOR;}
if(A_MPI_BXOR==op){return A_f_MPI_BXOR;}
if(A_MPI_LAND==op){return A_f_MPI_LAND;}
if(A_MPI_LOR==op){return A_f_MPI_LOR;}
if(A_MPI_LXOR==op){return A_f_MPI_LXOR;}
if(A_MPI_OP_NULL==op){return A_f_MPI_OP_NULL;}
return (int )(op);
}
A_MPI_Request A_MPI_Request_f2c(int  op){
if(A_f_MPI_REQUEST_NULL==op){return A_MPI_REQUEST_NULL;}
return (A_MPI_Request)(op);
}
int  A_MPI_Request_c2f(A_MPI_Request op){
if(A_MPI_REQUEST_NULL==op){return A_f_MPI_REQUEST_NULL;}
return (int )(op);
}
A_MPI_Group A_MPI_Group_f2c(int  op){
if(A_f_MPI_GROUP_NULL==op){return A_MPI_GROUP_NULL;}
if(A_f_MPI_GROUP_EMPTY==op){return A_MPI_GROUP_EMPTY;}
return (A_MPI_Group)(op);
}
int  A_MPI_Group_c2f(A_MPI_Group op){
if(A_MPI_GROUP_NULL==op){return A_f_MPI_GROUP_NULL;}
if(A_MPI_GROUP_EMPTY==op){return A_f_MPI_GROUP_EMPTY;}
return (int )(op);
}
A_MPI_Win A_MPI_Win_f2c(int  op){
if(A_f_MPI_WIN_NULL==op){return A_MPI_WIN_NULL;}
return (A_MPI_Win)(op);
}
int  A_MPI_Win_c2f(A_MPI_Win op){
if(A_MPI_WIN_NULL==op){return A_f_MPI_WIN_NULL;}
return (int )(op);
}
A_MPI_File A_MPI_File_f2c(int  op){
if(A_f_MPI_FILE_NULL==op){return A_MPI_FILE_NULL;}
return (A_MPI_File)(op);
}
int  A_MPI_File_c2f(A_MPI_File op){
if(A_MPI_FILE_NULL==op){return A_f_MPI_FILE_NULL;}
return (int )(op);
}
A_MPI_Info A_MPI_Info_f2c(int  op){
if(A_f_MPI_INFO_NULL==op){return A_MPI_INFO_NULL;}
return (A_MPI_Info)(op);
}
int  A_MPI_Info_c2f(A_MPI_Info op){
if(A_MPI_INFO_NULL==op){return A_f_MPI_INFO_NULL;}
return (int )(op);
}
int A_MPI_Status_f2c(const A_MPI_Fint *f_status, A_MPI_Status *c_status)
{
	if(f_status==A_f_MPI_STATUS_IGNORE||f_status==A_f_MPI_STATUSES_IGNORE)
		return -1;
	memcpy(c_status,f_status,A_f_MPI_STATUS_SIZE*sizeof(int));	
	return A_MPI_SUCCESS;
}
int A_MPI_Status_c2f(A_MPI_Status *c_status,const A_MPI_Fint *f_status)
{
	if(f_status==A_MPI_STATUS_IGNORE||f_status==A_MPI_STATUSES_IGNORE)
		return -1;
	memcpy(f_status,c_status,A_f_MPI_STATUS_SIZE*sizeof(int));	
	return A_MPI_SUCCESS;
}
#endif
