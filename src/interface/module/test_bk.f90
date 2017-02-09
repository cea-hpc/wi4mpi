!############################# Wi4MPI License ###########################
!# `04/04/2016`                                                         #
!# Copyright or (C) or Copr. Commissariat a l'Energie Atomique         #
!#                                                                      #
!# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
!# This file is part of the Wi4MPI library.                             #
!#                                                                      #
!# This software is governed by the CeCILL-C license under French law   #
!# and abiding by the rules of distribution of free software. You can   #
!# use, modify and/ or redistribute the software under the terms of     #
!# the CeCILL-C license as circulated by CEA, CNRS and INRIA at the     #
!# following URL http://www.cecill.info.                                #
!#                                                                      #
!# The fact that you are presently reading this means that you have     #
!# had knowledge of the CeCILL-C license and that you accept its        #
!# terms.                                                               #
!#                                                                      #
!# Authors:                                                             #
!#   - Delforge Tony <tony.delforge.tgcc@cea.fr>                        #
!#   - Ducrot Vincent <vincent.ducrot.tgcc@cea.fr>                      #
!#                                                                      #
!########################################################################
!
! This code is full generated
!
MODULE MPI_BASE
USE MPI_CONSTANTS 
IMPLICIT NONE
INTERFACE

SUBROUTINE MPI_Pcontrol(level,ierror)
INTEGER:: level
INTEGER:: ierror
END SUBROUTINE MPI_Pcontrol

!SUBROUTINE MPI_Send(buf,count,datatype,dest,tag,comm,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Send

!SUBROUTINE MPI_Recv(buf,count,datatype,source,tag,comm,status,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: source
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_Recv

SUBROUTINE MPI_Get_count(status,datatype,count,ierror)
USE MPI_CONSTANTS
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: datatype
INTEGER:: count
INTEGER:: ierror
END SUBROUTINE MPI_Get_count

!SUBROUTINE MPI_Bsend(buf,count,datatype,dest,tag,comm,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Bsend

!SUBROUTINE MPI_Ssend(buf,count,datatype,dest,tag,comm,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Ssend

!SUBROUTINE MPI_Rsend(buf,count,datatype,dest,tag,comm,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Rsend
!
!SUBROUTINE MPI_Buffer_attach(buffer,size,ierror)
!EXTERNAL:: buffer
!INTEGER:: size
!INTEGER:: ierror
!END SUBROUTINE MPI_Buffer_attach
!
!SUBROUTINE MPI_Buffer_detach(buffer_addr,size,ierror)
!EXTERNAL:: buffer_addr
!INTEGER:: size
!INTEGER:: ierror
!END SUBROUTINE MPI_Buffer_detach
!
!SUBROUTINE MPI_Isend(buf,count,datatype,dest,tag,comm,request,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Isend
!
!SUBROUTINE MPI_Ibsend(buf,count,datatype,dest,tag,comm,request,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ibsend
!
!SUBROUTINE MPI_Issend(buf,count,datatype,dest,tag,comm,request,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Issend
!
!SUBROUTINE MPI_Irsend(buf,count,datatype,dest,tag,comm,request,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Irsend
!
!SUBROUTINE MPI_Irecv(buf,count,datatype,source,tag,comm,request,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: source
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Irecv

SUBROUTINE MPI_Wait(request,status,ierror)
USE MPI_CONSTANTS
INTEGER:: request
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: ierror
END SUBROUTINE MPI_Wait

SUBROUTINE MPI_Test(request,flag,status,ierror)
USE MPI_CONSTANTS
INTEGER:: request
LOGICAL:: flag
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: ierror
END SUBROUTINE MPI_Test

SUBROUTINE MPI_Request_free(request,ierror)
INTEGER:: request
INTEGER:: ierror
END SUBROUTINE MPI_Request_free

SUBROUTINE MPI_Iprobe(source,tag,comm,flag,status,ierror)
USE MPI_CONSTANTS
INTEGER:: source
INTEGER:: tag
INTEGER:: comm
LOGICAL:: flag
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: ierror
END SUBROUTINE MPI_Iprobe

SUBROUTINE MPI_Probe(source,tag,comm,status,ierror)
USE MPI_CONSTANTS
INTEGER:: source
INTEGER:: tag
INTEGER:: comm
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: ierror
END SUBROUTINE MPI_Probe

SUBROUTINE MPI_Cancel(request,ierror)
INTEGER:: request
INTEGER:: ierror
END SUBROUTINE MPI_Cancel

SUBROUTINE MPI_Test_cancelled(status,flag,ierror)
USE MPI_CONSTANTS
INTEGER:: status(MPI_STATUS_SIZE)
LOGICAL:: flag
INTEGER:: ierror
END SUBROUTINE MPI_Test_cancelled

!SUBROUTINE MPI_Send_init(buf,count,datatype,dest,tag,comm,request,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Send_init
!
!SUBROUTINE MPI_Bsend_init(buf,count,datatype,dest,tag,comm,request,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Bsend_init
!
!SUBROUTINE MPI_Ssend_init(buf,count,datatype,dest,tag,comm,request,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ssend_init
!
!SUBROUTINE MPI_Rsend_init(buf,count,datatype,dest,tag,comm,request,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Rsend_init
!
!SUBROUTINE MPI_Recv_init(buf,count,datatype,source,tag,comm,request,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: source
!INTEGER:: tag
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Recv_init

SUBROUTINE MPI_Start(request,ierror)
INTEGER:: request
INTEGER:: ierror
END SUBROUTINE MPI_Start

!SUBROUTINE MPI_Sendrecv(sendbuf,sendcount,sendtype,dest,sendtag,recvbuf,recvcount,recvtype,source,recvtag,comm,status,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!INTEGER:: dest
!INTEGER:: sendtag
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: source
!INTEGER:: recvtag
!INTEGER:: comm
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_Sendrecv
!
!SUBROUTINE MPI_Sendrecv_replace(buf,count,datatype,dest,sendtag,source,recvtag,comm,status,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: dest
!INTEGER:: sendtag
!INTEGER:: source
!INTEGER:: recvtag
!INTEGER:: comm
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_Sendrecv_replace

SUBROUTINE MPI_Type_contiguous(count,oldtype,newtype,ierror)
INTEGER:: count
INTEGER:: oldtype
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_contiguous

SUBROUTINE MPI_Type_vector(count,blocklength,stride,oldtype,newtype,ierror)
INTEGER:: count
INTEGER:: blocklength
INTEGER:: stride
INTEGER:: oldtype
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_vector

SUBROUTINE MPI_Type_hvector(count,blocklength,stride,oldtype,newtype,ierror)
INTEGER:: count
INTEGER:: blocklength
INTEGER:: stride
INTEGER:: oldtype
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_hvector

SUBROUTINE MPI_Type_indexed(count,array_of_blocklengths,array_of_displacements,oldtype,newtype,ierror)
INTEGER:: count
INTEGER:: array_of_blocklengths(*)
INTEGER:: array_of_displacements(*)
INTEGER:: oldtype
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_indexed

SUBROUTINE MPI_Type_hindexed(count,array_of_blocklengths,array_of_displacements,oldtype,newtype,ierror)
INTEGER:: count
INTEGER:: array_of_blocklengths(*)
INTEGER:: array_of_displacements(*)
INTEGER:: oldtype
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_hindexed

SUBROUTINE MPI_Type_struct(count,array_of_blocklengths,array_of_displacements,array_of_types,newtype,ierror)
INTEGER:: count
INTEGER:: array_of_blocklengths(*)
INTEGER:: array_of_displacements(*)
INTEGER:: array_of_types(*)
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_struct

!SUBROUTINE MPI_Address(location,address,ierror)
!EXTERNAL:: location
!INTEGER:: address
!INTEGER:: ierror
!END SUBROUTINE MPI_Address

SUBROUTINE MPI_Type_extent(datatype,extent,ierror)
INTEGER:: datatype
INTEGER:: extent
INTEGER:: ierror
END SUBROUTINE MPI_Type_extent

SUBROUTINE MPI_Type_size(datatype,size,ierror)
INTEGER:: datatype
INTEGER:: size
INTEGER:: ierror
END SUBROUTINE MPI_Type_size

SUBROUTINE MPI_Type_lb(datatype,displacement,ierror)
INTEGER:: datatype
INTEGER:: displacement
INTEGER:: ierror
END SUBROUTINE MPI_Type_lb

SUBROUTINE MPI_Type_ub(datatype,displacement,ierror)
INTEGER:: datatype
INTEGER:: displacement
INTEGER:: ierror
END SUBROUTINE MPI_Type_ub

SUBROUTINE MPI_Type_commit(datatype,ierror)
INTEGER:: datatype
INTEGER:: ierror
END SUBROUTINE MPI_Type_commit

SUBROUTINE MPI_Type_free(datatype,ierror)
INTEGER:: datatype
INTEGER:: ierror
END SUBROUTINE MPI_Type_free

SUBROUTINE MPI_Get_elements(status,datatype,count,ierror)
USE MPI_CONSTANTS
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: datatype
INTEGER:: count
INTEGER:: ierror
END SUBROUTINE MPI_Get_elements

!SUBROUTINE MPI_Pack(inbuf,incount,datatype,outbuf,outsize,position,comm,ierror)
!EXTERNAL:: inbuf
!INTEGER:: incount
!INTEGER:: datatype
!EXTERNAL:: outbuf
!INTEGER:: outsize
!INTEGER:: position
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Pack

!SUBROUTINE MPI_Unpack(inbuf,insize,position,outbuf,outcount,datatype,comm,ierror)
!EXTERNAL:: inbuf
!INTEGER:: insize
!INTEGER:: position
!EXTERNAL:: outbuf
!INTEGER:: outcount
!INTEGER:: datatype
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Unpack

SUBROUTINE MPI_Pack_size(incount,datatype,comm,size,ierror)
INTEGER:: incount
INTEGER:: datatype
INTEGER:: comm
INTEGER:: size
INTEGER:: ierror
END SUBROUTINE MPI_Pack_size

SUBROUTINE MPI_Barrier(comm,ierror)
INTEGER:: comm
INTEGER:: ierror
END SUBROUTINE MPI_Barrier

!SUBROUTINE MPI_Bcast(buffer,count,datatype,root,comm,ierror)
!EXTERNAL:: buffer
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: root
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Bcast

!SUBROUTINE MPI_Gather(sendbuf,sendcount,sendtype,recvbuf,recvcount,recvtype,root,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: root
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Gather
!
!SUBROUTINE MPI_Gatherv(sendbuf,sendcount,sendtype,recvbuf,recvcounts,displs,recvtype,root,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: displs
!INTEGER:: recvtype
!INTEGER:: root
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Gatherv
!
!SUBROUTINE MPI_Scatter(sendbuf,sendcount,sendtype,recvbuf,recvcount,recvtype,root,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: root
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Scatter
!
!SUBROUTINE MPI_Scatterv(sendbuf,sendcounts,displs,sendtype,recvbuf,recvcount,recvtype,root,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcounts
!INTEGER:: displs
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: root
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Scatterv
!
!SUBROUTINE MPI_Allgather(sendbuf,sendcount,sendtype,recvbuf,recvcount,recvtype,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Allgather
!
!SUBROUTINE MPI_Allgatherv(sendbuf,sendcount,sendtype,recvbuf,recvcounts,displs,recvtype,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: displs
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Allgatherv
!
!SUBROUTINE MPI_Alltoall(sendbuf,sendcount,sendtype,recvbuf,recvcount,recvtype,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Alltoall
!
!SUBROUTINE MPI_Alltoallv(sendbuf,sendcounts,sdispls,sendtype,recvbuf,recvcounts,rdispls,recvtype,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcounts
!INTEGER:: sdispls
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: rdispls
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Alltoallv
!
!SUBROUTINE MPI_Exscan(sendbuf,recvbuf,count,datatype,op,comm,ierror)
!EXTERNAL:: sendbuf
!EXTERNAL:: recvbuf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: op
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Exscan

!SUBROUTINE MPI_Reduce(sendbuf,recvbuf,count,datatype,op,root,comm,ierror)
!TYPE(*), INTENT(IN)  sendbuf
!TYPE(*) recvbuf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: op
!INTEGER:: root
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Reduce

!SUBROUTINE MPI_Op_create(user_fn,commute,op,ierror)
!EXTERNAL:: user_fn
!INTEGER:: commute
!INTEGER:: op
!INTEGER:: ierror
!END SUBROUTINE MPI_Op_create

SUBROUTINE MPI_Op_free(op,ierror)
INTEGER:: op
INTEGER:: ierror
END SUBROUTINE MPI_Op_free

!SUBROUTINE MPI_Allreduce(sendbuf,recvbuf,count,datatype,op,comm,ierror)
!EXTERNAL:: sendbuf
!EXTERNAL:: recvbuf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: op
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Allreduce

!SUBROUTINE MPI_Scan(sendbuf,recvbuf,count,datatype,op,comm,ierror)
!EXTERNAL:: sendbuf
!EXTERNAL:: recvbuf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: op
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Scan

SUBROUTINE MPI_Group_size(group,size,ierror)
INTEGER:: group
INTEGER:: size
INTEGER:: ierror
END SUBROUTINE MPI_Group_size

SUBROUTINE MPI_Group_rank(group,rank,ierror)
INTEGER:: group
INTEGER:: rank
INTEGER:: ierror
END SUBROUTINE MPI_Group_rank

SUBROUTINE MPI_Group_compare(group1,group2,result,ierror)
INTEGER:: group1
INTEGER:: group2
INTEGER:: result
INTEGER:: ierror
END SUBROUTINE MPI_Group_compare

SUBROUTINE MPI_Comm_group(comm,group,ierror)
INTEGER:: comm
INTEGER:: group
INTEGER:: ierror
END SUBROUTINE MPI_Comm_group

SUBROUTINE MPI_Group_union(group1,group2,newgroup,ierror)
INTEGER:: group1
INTEGER:: group2
INTEGER:: newgroup
INTEGER:: ierror
END SUBROUTINE MPI_Group_union

SUBROUTINE MPI_Group_intersection(group1,group2,newgroup,ierror)
INTEGER:: group1
INTEGER:: group2
INTEGER:: newgroup
INTEGER:: ierror
END SUBROUTINE MPI_Group_intersection

SUBROUTINE MPI_Group_difference(group1,group2,newgroup,ierror)
INTEGER:: group1
INTEGER:: group2
INTEGER:: newgroup
INTEGER:: ierror
END SUBROUTINE MPI_Group_difference

SUBROUTINE MPI_Group_free(group,ierror)
INTEGER:: group
INTEGER:: ierror
END SUBROUTINE MPI_Group_free

SUBROUTINE MPI_Comm_size(comm,size,ierror)
INTEGER :: comm
INTEGER:: size
INTEGER:: ierror
END SUBROUTINE MPI_Comm_size

SUBROUTINE MPI_Comm_rank(comm,rank,ierror)
INTEGER:: comm
INTEGER:: rank
INTEGER:: ierror
END SUBROUTINE MPI_Comm_rank

SUBROUTINE MPI_Comm_compare(comm1,comm2,result,ierror)
INTEGER:: comm1
INTEGER:: comm2
INTEGER:: result
INTEGER:: ierror
END SUBROUTINE MPI_Comm_compare

SUBROUTINE MPI_Comm_dup(comm,newcomm,ierror)
INTEGER:: comm
INTEGER:: newcomm
INTEGER:: ierror
END SUBROUTINE MPI_Comm_dup

SUBROUTINE MPI_Comm_dup_with_info(comm,info,newcomm,ierror)
INTEGER:: comm
INTEGER:: info
INTEGER:: newcomm
INTEGER:: ierror
END SUBROUTINE MPI_Comm_dup_with_info

SUBROUTINE MPI_Comm_create(comm,group,newcomm,ierror)
INTEGER:: comm
INTEGER:: group
INTEGER:: newcomm
INTEGER:: ierror
END SUBROUTINE MPI_Comm_create

SUBROUTINE MPI_Comm_split(comm,color,key,newcomm,ierror)
INTEGER:: comm
INTEGER:: color
INTEGER:: key
INTEGER:: newcomm
INTEGER:: ierror
END SUBROUTINE MPI_Comm_split

SUBROUTINE MPI_Comm_free(comm,ierror)
INTEGER:: comm
INTEGER:: ierror
END SUBROUTINE MPI_Comm_free

SUBROUTINE MPI_Comm_test_inter(comm,flag,ierror)
INTEGER:: comm
LOGICAL:: flag
INTEGER:: ierror
END SUBROUTINE MPI_Comm_test_inter

SUBROUTINE MPI_Comm_remote_size(comm,size,ierror)
INTEGER:: comm
INTEGER:: size
INTEGER:: ierror
END SUBROUTINE MPI_Comm_remote_size

SUBROUTINE MPI_Comm_remote_group(comm,group,ierror)
INTEGER:: comm
INTEGER:: group
INTEGER:: ierror
END SUBROUTINE MPI_Comm_remote_group

SUBROUTINE MPI_Intercomm_create(local_comm,local_leader,peer_comm,remote_leader,tag,newintercomm,ierror)
INTEGER:: local_comm
INTEGER:: local_leader
INTEGER:: peer_comm
INTEGER:: remote_leader
INTEGER:: tag
INTEGER:: newintercomm
INTEGER:: ierror
END SUBROUTINE MPI_Intercomm_create

SUBROUTINE MPI_Intercomm_merge(intercomm,high,newintracomm,ierror)
INTEGER:: intercomm
LOGICAL:: high
INTEGER:: newintracomm
INTEGER:: ierror
END SUBROUTINE MPI_Intercomm_merge

!SUBROUTINE MPI_Keyval_create(copy_fn,delete_fn,keyval,extra_state,ierror)
!EXTERNAL:: copy_fn
!EXTERNAL:: delete_fn
!INTEGER:: keyval
!EXTERNAL:: extra_state
!INTEGER:: ierror
!END SUBROUTINE MPI_Keyval_create

SUBROUTINE MPI_Keyval_free(keyval,ierror)
INTEGER:: keyval
INTEGER:: ierror
END SUBROUTINE MPI_Keyval_free

SUBROUTINE MPI_Attr_put(comm,keyval,attribute_val,ierror)
INTEGER:: comm
INTEGER:: keyval
INTEGER:: attribute_val
INTEGER:: ierror
END SUBROUTINE MPI_Attr_put

SUBROUTINE MPI_Attr_get(comm,keyval,attribute_val,flag,ierror)
INTEGER:: comm
INTEGER:: keyval
INTEGER:: attribute_val
LOGICAL:: flag
INTEGER:: ierror
END SUBROUTINE MPI_Attr_get

SUBROUTINE MPI_Attr_delete(comm,keyval,ierror)
INTEGER:: comm
INTEGER:: keyval
INTEGER:: ierror
END SUBROUTINE MPI_Attr_delete

SUBROUTINE MPI_Topo_test(comm,status,ierror)
USE MPI_CONSTANTS
INTEGER:: comm
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: ierror
END SUBROUTINE MPI_Topo_test

SUBROUTINE MPI_Graphdims_get(comm,nnodes,nedges,ierror)
INTEGER:: comm
INTEGER:: nnodes
INTEGER:: nedges
INTEGER:: ierror
END SUBROUTINE MPI_Graphdims_get

SUBROUTINE MPI_Cartdim_get(comm,ndims,ierror)
INTEGER:: comm
INTEGER:: ndims
INTEGER:: ierror
END SUBROUTINE MPI_Cartdim_get

SUBROUTINE MPI_Graph_neighbors_count(comm,rank,nneighbors,ierror)
INTEGER:: comm
INTEGER:: rank
INTEGER:: nneighbors
INTEGER:: ierror
END SUBROUTINE MPI_Graph_neighbors_count

SUBROUTINE MPI_Cart_shift(comm,direction,disp,rank_source,rank_dest,ierror)
INTEGER:: comm
INTEGER:: direction
INTEGER:: disp
INTEGER:: rank_source
INTEGER:: rank_dest
INTEGER:: ierror
END SUBROUTINE MPI_Cart_shift

SUBROUTINE MPI_Get_version(version,subversion,ierror)
INTEGER:: version
INTEGER:: subversion
INTEGER:: ierror
END SUBROUTINE MPI_Get_version

SUBROUTINE MPI_Get_library_version(version,resultlen,ierror)
CHARACTER(LEN=*):: version
INTEGER:: resultlen
INTEGER:: ierror
END SUBROUTINE MPI_Get_library_version

!SUBROUTINE MPI_Errhandler_create(function,errhandler,ierror)
!EXTERNAL:: function
!INTEGER:: errhandler
!INTEGER:: ierror
!END SUBROUTINE MPI_Errhandler_create

SUBROUTINE MPI_Errhandler_set(comm,errhandler,ierror)
INTEGER:: comm
INTEGER:: errhandler
INTEGER:: ierror
END SUBROUTINE MPI_Errhandler_set

SUBROUTINE MPI_Errhandler_get(comm,errhandler,ierror)
INTEGER:: comm
INTEGER:: errhandler
INTEGER:: ierror
END SUBROUTINE MPI_Errhandler_get

SUBROUTINE MPI_Errhandler_free(errhandler,ierror)
INTEGER:: errhandler
INTEGER:: ierror
END SUBROUTINE MPI_Errhandler_free

SUBROUTINE MPI_Error_class(errorcode,errorclass,ierror)
INTEGER:: errorcode
INTEGER:: errorclass
INTEGER:: ierror
END SUBROUTINE MPI_Error_class

SUBROUTINE MPI_Initialized(flag,ierror)
LOGICAL:: flag
INTEGER:: ierror
END SUBROUTINE MPI_Initialized

SUBROUTINE MPI_Abort(comm,errorcode,ierror)
INTEGER:: comm
INTEGER:: errorcode
INTEGER:: ierror
END SUBROUTINE MPI_Abort

SUBROUTINE MPI_Init(ierror)
INTEGER:: ierror
END SUBROUTINE MPI_Init

SUBROUTINE MPI_Close_port(port_name,ierror)
CHARACTER(LEN=*):: port_name
INTEGER:: ierror
END SUBROUTINE MPI_Close_port

SUBROUTINE MPI_Comm_accept(port_name,info,root,comm,newcomm,ierror)
CHARACTER(LEN=*):: port_name
INTEGER:: info
INTEGER:: root
INTEGER:: comm
INTEGER:: newcomm
INTEGER:: ierror
END SUBROUTINE MPI_Comm_accept

SUBROUTINE MPI_Comm_connect(port_name,info,root,comm,newcomm,ierror)
CHARACTER(LEN=*):: port_name
INTEGER:: info
INTEGER:: root
INTEGER:: comm
INTEGER:: newcomm
INTEGER:: ierror
END SUBROUTINE MPI_Comm_connect

SUBROUTINE MPI_Comm_disconnect(comm,ierror)
INTEGER:: comm
INTEGER:: ierror
END SUBROUTINE MPI_Comm_disconnect

SUBROUTINE MPI_Comm_get_parent(parent,ierror)
INTEGER:: parent
INTEGER:: ierror
END SUBROUTINE MPI_Comm_get_parent

SUBROUTINE MPI_Comm_join(fd,intercomm,ierror)
INTEGER:: fd
INTEGER:: intercomm
INTEGER:: ierror
END SUBROUTINE MPI_Comm_join

SUBROUTINE MPI_Lookup_name(service_name,info,port_name,ierror)
CHARACTER(LEN=*):: service_name
INTEGER:: info
CHARACTER(LEN=*):: port_name
INTEGER:: ierror
END SUBROUTINE MPI_Lookup_name

SUBROUTINE MPI_Open_port(info,port_name,ierror)
INTEGER:: info
CHARACTER(LEN=*):: port_name
INTEGER:: ierror
END SUBROUTINE MPI_Open_port

SUBROUTINE MPI_Publish_name(service_name,info,port_name,ierror)
CHARACTER(LEN=*):: service_name
INTEGER:: info
CHARACTER(LEN=*):: port_name
INTEGER:: ierror
END SUBROUTINE MPI_Publish_name

SUBROUTINE MPI_Unpublish_name(service_name,info,port_name,ierror)
CHARACTER(LEN=*):: service_name
INTEGER:: info
CHARACTER(LEN=*):: port_name
INTEGER:: ierror
END SUBROUTINE MPI_Unpublish_name

SUBROUTINE MPI_Comm_set_info(comm,info,ierror)
INTEGER:: comm
INTEGER:: info
INTEGER:: ierror
END SUBROUTINE MPI_Comm_set_info

SUBROUTINE MPI_Comm_get_info(comm,info,ierror)
INTEGER:: comm
INTEGER:: info
INTEGER:: ierror
END SUBROUTINE MPI_Comm_get_info

!SUBROUTINE MPI_Accumulate(origin_addr,origin_count,origin_datatype,target_rank,target_disp,target_count,target_datatype,op,win,ierror)
!EXTERNAL:: origin_addr
!INTEGER:: origin_count
!INTEGER:: origin_datatype
!INTEGER:: target_rank
!INTEGER:: target_disp
!INTEGER:: target_count
!INTEGER:: target_datatype
!INTEGER:: op
!INTEGER:: win
!INTEGER:: ierror
!END SUBROUTINE MPI_Accumulate

!SUBROUTINE MPI_Get(origin_addr,origin_count,origin_datatype,target_rank,target_disp,target_count,target_datatype,win,ierror)
!EXTERNAL:: origin_addr
!INTEGER:: origin_count
!INTEGER:: origin_datatype
!INTEGER:: target_rank
!INTEGER:: target_disp
!INTEGER:: target_count
!INTEGER:: target_datatype
!INTEGER:: win
!INTEGER:: ierror
!END SUBROUTINE MPI_Get

!SUBROUTINE MPI_Put(origin_addr,origin_count,origin_datatype,target_rank,target_disp,target_count,target_datatype,win,ierror)
!EXTERNAL:: origin_addr
!INTEGER:: origin_count
!INTEGER:: origin_datatype
!INTEGER:: target_rank
!INTEGER:: target_disp
!INTEGER:: target_count
!INTEGER:: target_datatype
!INTEGER:: win
!INTEGER:: ierror
!END SUBROUTINE MPI_Put

SUBROUTINE MPI_Win_complete(win,ierror)
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_complete

!SUBROUTINE MPI_Win_create(base,size,disp_unit,info,comm,win,ierror)
!EXTERNAL:: base
!INTEGER:: size
!INTEGER:: disp_unit
!INTEGER:: info
!INTEGER:: comm
!INTEGER:: win
!INTEGER:: ierror
!END SUBROUTINE MPI_Win_create

SUBROUTINE MPI_Win_fence(assert,win,ierror)
INTEGER:: assert
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_fence

SUBROUTINE MPI_Win_free(win,ierror)
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_free

SUBROUTINE MPI_Win_get_group(win,group,ierror)
INTEGER:: win
INTEGER:: group
INTEGER:: ierror
END SUBROUTINE MPI_Win_get_group

SUBROUTINE MPI_Win_lock(lock_type,rank,assert,win,ierror)
INTEGER:: lock_type
INTEGER:: rank
INTEGER:: assert
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_lock

SUBROUTINE MPI_Win_post(group,assert,win,ierror)
INTEGER:: group
INTEGER:: assert
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_post

SUBROUTINE MPI_Win_start(group,assert,win,ierror)
INTEGER:: group
INTEGER:: assert
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_start

SUBROUTINE MPI_Win_test(win,flag,ierror)
INTEGER:: win
LOGICAL:: flag
INTEGER:: ierror
END SUBROUTINE MPI_Win_test

SUBROUTINE MPI_Win_unlock(rank,win,ierror)
INTEGER:: rank
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_unlock

SUBROUTINE MPI_Win_wait(win,ierror)
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_wait

!SUBROUTINE MPI_Win_allocate(size,disp_unit,info,comm,baseptr,win,ierror)
!INTEGER:: size
!INTEGER:: disp_unit
!INTEGER:: info
!INTEGER:: comm
!EXTERNAL:: baseptr
!INTEGER:: win
!INTEGER:: ierror
!END SUBROUTINE MPI_Win_allocate
!
!SUBROUTINE MPI_Win_allocate_shared(size,disp_unit,info,comm,baseptr,win,ierror)
!INTEGER:: size
!INTEGER:: disp_unit
!INTEGER:: info
!INTEGER:: comm
!EXTERNAL:: baseptr
!INTEGER:: win
!INTEGER:: ierror
!END SUBROUTINE MPI_Win_allocate_shared
!
!SUBROUTINE MPI_Win_shared_query(win,rank,size,disp_unit,baseptr,ierror)
!INTEGER:: win
!INTEGER:: rank
!INTEGER:: size
!INTEGER:: disp_unit
!EXTERNAL:: baseptr
!INTEGER:: ierror
!END SUBROUTINE MPI_Win_shared_query

SUBROUTINE MPI_Win_create_dynamic(info,comm,win,ierror)
INTEGER:: info
INTEGER:: comm
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_create_dynamic

!SUBROUTINE MPI_Win_attach(win,base,size,ierror)
!INTEGER:: win
!EXTERNAL:: base
!INTEGER:: size
!INTEGER:: ierror
!END SUBROUTINE MPI_Win_attach
!
!SUBROUTINE MPI_Win_detach(win,base,ierror)
!INTEGER:: win
!EXTERNAL:: base
!INTEGER:: ierror
!END SUBROUTINE MPI_Win_detach

SUBROUTINE MPI_Win_get_info(win,info_used,ierror)
INTEGER:: win
INTEGER:: info_used
INTEGER:: ierror
END SUBROUTINE MPI_Win_get_info

SUBROUTINE MPI_Win_set_info(win,info,ierror)
INTEGER:: win
INTEGER:: info
INTEGER:: ierror
END SUBROUTINE MPI_Win_set_info

!SUBROUTINE MPI_Get_accumulate(origin_addr,origin_count,origin_datatype,result_addr,result_count,result_datatype,target_rank,target_disp,target_count,target_datatype,op,win,ierror)
!EXTERNAL:: origin_addr
!INTEGER:: origin_count
!INTEGER:: origin_datatype
!EXTERNAL:: result_addr
!INTEGER:: result_count
!INTEGER:: result_datatype
!INTEGER:: target_rank
!INTEGER:: target_disp
!INTEGER:: target_count
!INTEGER:: target_datatype
!INTEGER:: op
!INTEGER:: win
!INTEGER:: ierror
!END SUBROUTINE MPI_Get_accumulate
!
!SUBROUTINE MPI_Fetch_and_op(origin_addr,result_addr,datatype,target_rank,target_disp,op,win,ierror)
!EXTERNAL:: origin_addr
!EXTERNAL:: result_addr
!INTEGER:: datatype
!INTEGER:: target_rank
!INTEGER:: target_disp
!INTEGER:: op
!INTEGER:: win
!INTEGER:: ierror
!END SUBROUTINE MPI_Fetch_and_op
!
!SUBROUTINE MPI_Compare_and_swap(origin_addr,compare_addr,result_addr,datatype,target_rank,target_disp,win,ierror)
!EXTERNAL:: origin_addr
!EXTERNAL:: compare_addr
!EXTERNAL:: result_addr
!INTEGER:: datatype
!INTEGER:: target_rank
!INTEGER:: target_disp
!INTEGER:: win
!INTEGER:: ierror
!END SUBROUTINE MPI_Compare_and_swap
!
!SUBROUTINE MPI_Rput(origin_addr,origin_count,origin_datatype,target_rank,target_disp,target_count,target_datatype,win,request,ierror)
!EXTERNAL:: origin_addr
!INTEGER:: origin_count
!INTEGER:: origin_datatype
!INTEGER:: target_rank
!INTEGER:: target_disp
!INTEGER:: target_count
!INTEGER:: target_datatype
!INTEGER:: win
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Rput
!
!SUBROUTINE MPI_Rget(origin_addr,origin_count,origin_datatype,target_rank,target_disp,target_count,target_datatype,win,request,ierror)
!EXTERNAL:: origin_addr
!INTEGER:: origin_count
!INTEGER:: origin_datatype
!INTEGER:: target_rank
!INTEGER:: target_disp
!INTEGER:: target_count
!INTEGER:: target_datatype
!INTEGER:: win
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Rget
!
!SUBROUTINE MPI_Raccumulate(origin_addr,origin_count,origin_datatype,target_rank,target_disp,target_count,target_datatype,op,win,request,ierror)
!EXTERNAL:: origin_addr
!INTEGER:: origin_count
!INTEGER:: origin_datatype
!INTEGER:: target_rank
!INTEGER:: target_disp
!INTEGER:: target_count
!INTEGER:: target_datatype
!INTEGER:: op
!INTEGER:: win
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Raccumulate
!
!SUBROUTINE MPI_Rget_accumulate(origin_addr,origin_count,origin_datatype,result_addr,result_count,result_datatype,target_rank,target_disp,target_count,target_datatype,op,win,request,ierror)
!EXTERNAL:: origin_addr
!INTEGER:: origin_count
!INTEGER:: origin_datatype
!EXTERNAL:: result_addr
!INTEGER:: result_count
!INTEGER:: result_datatype
!INTEGER:: target_rank
!INTEGER:: target_disp
!INTEGER:: target_count
!INTEGER:: target_datatype
!INTEGER:: op
!INTEGER:: win
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Rget_accumulate

SUBROUTINE MPI_Win_lock_all(assert,win,ierror)
INTEGER:: assert
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_lock_all

SUBROUTINE MPI_Win_unlock_all(win,ierror)
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_unlock_all

SUBROUTINE MPI_Win_flush(rank,win,ierror)
INTEGER:: rank
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_flush

SUBROUTINE MPI_Win_flush_all(win,ierror)
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_flush_all

SUBROUTINE MPI_Win_flush_local(rank,win,ierror)
INTEGER:: rank
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_flush_local

SUBROUTINE MPI_Win_flush_local_all(win,ierror)
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_flush_local_all

SUBROUTINE MPI_Win_sync(win,ierror)
INTEGER:: win
INTEGER:: ierror
END SUBROUTINE MPI_Win_sync

SUBROUTINE MPI_Add_error_class(errorclass,ierror)
INTEGER:: errorclass
INTEGER:: ierror
END SUBROUTINE MPI_Add_error_class

SUBROUTINE MPI_Add_error_code(errorclass,errorcode,ierror)
INTEGER:: errorclass
INTEGER:: errorcode
INTEGER:: ierror
END SUBROUTINE MPI_Add_error_code

SUBROUTINE MPI_Add_error_string(errorcode,string,ierror)
INTEGER:: errorcode
CHARACTER(LEN=*):: string
INTEGER:: ierror
END SUBROUTINE MPI_Add_error_string

SUBROUTINE MPI_Comm_call_errhandler(comm,errorcode,ierror)
INTEGER:: comm
INTEGER:: errorcode
INTEGER:: ierror
END SUBROUTINE MPI_Comm_call_errhandler

!SUBROUTINE MPI_Comm_create_keyval(comm_copy_attr_fn,comm_delete_attr_fn,comm_keyval,extra_state,ierror)
!EXTERNAL:: comm_copy_attr_fn
!EXTERNAL:: comm_delete_attr_fn
!INTEGER:: comm_keyval
!EXTERNAL:: extra_state
!INTEGER:: ierror
!END SUBROUTINE MPI_Comm_create_keyval

SUBROUTINE MPI_Comm_delete_attr(comm,comm_keyval,ierror)
INTEGER:: comm
INTEGER:: comm_keyval
INTEGER:: ierror
END SUBROUTINE MPI_Comm_delete_attr

SUBROUTINE MPI_Comm_free_keyval(comm_keyval,ierror)
INTEGER:: comm_keyval
INTEGER:: ierror
END SUBROUTINE MPI_Comm_free_keyval

!SUBROUTINE MPI_Comm_get_attr(comm,comm_keyval,attribute_val,flag,ierror)
!INTEGER:: comm
!INTEGER:: comm_keyval
!EXTERNAL:: attribute_val
!INTEGER:: flag
!INTEGER:: ierror
!END SUBROUTINE MPI_Comm_get_attr

SUBROUTINE MPI_Comm_get_name(comm,comm_name,resultlen,ierror)
INTEGER:: comm
CHARACTER(LEN=*):: comm_name
INTEGER:: resultlen
INTEGER:: ierror
END SUBROUTINE MPI_Comm_get_name

!SUBROUTINE MPI_Comm_set_attr(comm,comm_keyval,attribute_val,ierror)
!INTEGER:: comm
!INTEGER:: comm_keyval
!EXTERNAL:: attribute_val
!INTEGER:: ierror
!END SUBROUTINE MPI_Comm_set_attr

SUBROUTINE MPI_Comm_set_name(comm,comm_name,ierror)
INTEGER:: comm
CHARACTER(LEN=*):: comm_name
INTEGER:: ierror
END SUBROUTINE MPI_Comm_set_name

SUBROUTINE MPI_File_call_errhandler(fh,errorcode,ierror)
INTEGER:: fh
INTEGER:: errorcode
INTEGER:: ierror
END SUBROUTINE MPI_File_call_errhandler

SUBROUTINE MPI_Grequest_complete(request,ierror)
INTEGER:: request
INTEGER:: ierror
END SUBROUTINE MPI_Grequest_complete

!SUBROUTINE MPI_Grequest_start(query_fn,free_fn,cancel_fn,extra_state,request,ierror)
!EXTERNAL:: query_fn
!EXTERNAL:: free_fn
!EXTERNAL:: cancel_fn
!EXTERNAL:: extra_state
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Grequest_start

SUBROUTINE MPI_Init_thread(required,provided,ierror)
INTEGER:: required
INTEGER:: provided
INTEGER:: ierror
END SUBROUTINE MPI_Init_thread

SUBROUTINE MPI_Is_thread_main(flag,ierror)
LOGICAL:: flag
INTEGER:: ierror
END SUBROUTINE MPI_Is_thread_main

SUBROUTINE MPI_Query_thread(provided,ierror)
INTEGER:: provided
INTEGER:: ierror
END SUBROUTINE MPI_Query_thread

SUBROUTINE MPI_Status_set_cancelled(status,flag,ierror)
USE MPI_CONSTANTS
INTEGER:: status(MPI_STATUS_SIZE)
LOGICAL:: flag
INTEGER:: ierror
END SUBROUTINE MPI_Status_set_cancelled

SUBROUTINE MPI_Status_set_elements(status,datatype,count,ierror)
USE MPI_CONSTANTS
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: datatype
INTEGER:: count
INTEGER:: ierror
END SUBROUTINE MPI_Status_set_elements

!SUBROUTINE MPI_Type_create_keyval(type_copy_attr_fn,type_delete_attr_fn,type_keyval,extra_state,ierror)
!EXTERNAL:: type_copy_attr_fn
!EXTERNAL:: type_delete_attr_fn
!INTEGER:: type_keyval
!EXTERNAL:: extra_state
!INTEGER:: ierror
!END SUBROUTINE MPI_Type_create_keyval

SUBROUTINE MPI_Type_delete_attr(datatype,type_keyval,ierror)
INTEGER:: datatype
INTEGER:: type_keyval
INTEGER:: ierror
END SUBROUTINE MPI_Type_delete_attr

SUBROUTINE MPI_Type_dup(oldtype,newtype,ierror)
INTEGER:: oldtype
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_dup

SUBROUTINE MPI_Type_free_keyval(type_keyval,ierror)
INTEGER:: type_keyval
INTEGER:: ierror
END SUBROUTINE MPI_Type_free_keyval

!SUBROUTINE MPI_Type_get_attr(datatype,type_keyval,attribute_val,flag,ierror)
!INTEGER:: datatype
!INTEGER:: type_keyval
!EXTERNAL:: attribute_val
!INTEGER:: flag
!INTEGER:: ierror
!END SUBROUTINE MPI_Type_get_attr

SUBROUTINE MPI_Type_get_envelope(datatype,num_integers,num_addresses,num_datatypes,combiner,ierror)
INTEGER:: datatype
INTEGER:: num_integers
INTEGER:: num_addresses
INTEGER:: num_datatypes
INTEGER:: combiner
INTEGER:: ierror
END SUBROUTINE MPI_Type_get_envelope

SUBROUTINE MPI_Type_get_name(datatype,type_name,resultlen,ierror)
INTEGER:: datatype
CHARACTER(LEN=*):: type_name
INTEGER:: resultlen
INTEGER:: ierror
END SUBROUTINE MPI_Type_get_name

!SUBROUTINE MPI_Type_set_attr(datatype,type_keyval,attribute_val,ierror)
!INTEGER:: datatype
!INTEGER:: type_keyval
!EXTERNAL:: attribute_val
!INTEGER:: ierror
!END SUBROUTINE MPI_Type_set_attr

SUBROUTINE MPI_Type_set_name(datatype,type_name,ierror)
INTEGER:: datatype
CHARACTER(LEN=*):: type_name
INTEGER:: ierror
END SUBROUTINE MPI_Type_set_name

SUBROUTINE MPI_Type_match_size(typeclass,size,datatype,ierror)
INTEGER:: typeclass
INTEGER:: size
INTEGER:: datatype
INTEGER:: ierror
END SUBROUTINE MPI_Type_match_size

SUBROUTINE MPI_Win_call_errhandler(win,errorcode,ierror)
INTEGER:: win
INTEGER:: errorcode
INTEGER:: ierror
END SUBROUTINE MPI_Win_call_errhandler

!SUBROUTINE MPI_Win_create_keyval(win_copy_attr_fn,win_delete_attr_fn,win_keyval,extra_state,ierror)
!EXTERNAL:: win_copy_attr_fn
!EXTERNAL:: win_delete_attr_fn
!INTEGER:: win_keyval
!EXTERNAL:: extra_state
!INTEGER:: ierror
!END SUBROUTINE MPI_Win_create_keyval

SUBROUTINE MPI_Win_delete_attr(win,win_keyval,ierror)
INTEGER:: win
INTEGER:: win_keyval
INTEGER:: ierror
END SUBROUTINE MPI_Win_delete_attr

SUBROUTINE MPI_Win_free_keyval(win_keyval,ierror)
INTEGER:: win_keyval
INTEGER:: ierror
END SUBROUTINE MPI_Win_free_keyval

!SUBROUTINE MPI_Win_get_attr(win,win_keyval,attribute_val,flag,ierror)
!INTEGER:: win
!INTEGER:: win_keyval
!EXTERNAL:: attribute_val
!INTEGER:: flag
!INTEGER:: ierror
!END SUBROUTINE MPI_Win_get_attr

SUBROUTINE MPI_Win_get_name(win,win_name,resultlen,ierror)
INTEGER:: win
CHARACTER(LEN=*):: win_name
INTEGER:: resultlen
INTEGER:: ierror
END SUBROUTINE MPI_Win_get_name

!SUBROUTINE MPI_Win_set_attr(win,win_keyval,attribute_val,ierror)
!INTEGER:: win
!INTEGER:: win_keyval
!EXTERNAL:: attribute_val
!INTEGER:: ierror
!END SUBROUTINE MPI_Win_set_attr

SUBROUTINE MPI_Win_set_name(win,win_name,ierror)
INTEGER:: win
CHARACTER(LEN=*):: win_name
INTEGER:: ierror
END SUBROUTINE MPI_Win_set_name

!SUBROUTINE MPI_Alloc_mem(size,info,baseptr,ierror)
!INTEGER:: size
!INTEGER:: info
!EXTERNAL:: baseptr
!INTEGER:: ierror
!END SUBROUTINE MPI_Alloc_mem

!SUBROUTINE MPI_Comm_create_errhandler(comm_errhandler_fn,errhandler,ierror)
!EXTERNAL:: comm_errhandler_fn
!INTEGER:: errhandler
!INTEGER:: ierror
!END SUBROUTINE MPI_Comm_create_errhandler

SUBROUTINE MPI_Comm_get_errhandler(comm,errhandler,ierror)
INTEGER:: comm
INTEGER:: errhandler
INTEGER:: ierror
END SUBROUTINE MPI_Comm_get_errhandler

SUBROUTINE MPI_Comm_set_errhandler(comm,errhandler,ierror)
INTEGER:: comm
INTEGER:: errhandler
INTEGER:: ierror
END SUBROUTINE MPI_Comm_set_errhandler

!SUBROUTINE MPI_File_create_errhandler(file_errhandler_fn,errhandler,ierror)
!EXTERNAL:: file_errhandler_fn
!INTEGER:: errhandler
!INTEGER:: ierror
!END SUBROUTINE MPI_File_create_errhandler

SUBROUTINE MPI_File_get_errhandler(file,errhandler,ierror)
INTEGER:: file
INTEGER:: errhandler
INTEGER:: ierror
END SUBROUTINE MPI_File_get_errhandler

SUBROUTINE MPI_File_set_errhandler(file,errhandler,ierror)
INTEGER:: file
INTEGER:: errhandler
INTEGER:: ierror
END SUBROUTINE MPI_File_set_errhandler

SUBROUTINE MPI_Finalized(flag,ierror)
LOGICAL:: flag
INTEGER:: ierror
END SUBROUTINE MPI_Finalized

!SUBROUTINE MPI_Free_mem(base,ierror)
!EXTERNAL:: base
!INTEGER:: ierror
!END SUBROUTINE MPI_Free_mem

!SUBROUTINE MPI_Get_address(location,address,ierror)
!EXTERNAL:: location
!INTEGER:: address
!INTEGER:: ierror
!END SUBROUTINE MPI_Get_address

SUBROUTINE MPI_Info_create(info,ierror)
INTEGER:: info
INTEGER:: ierror
END SUBROUTINE MPI_Info_create

SUBROUTINE MPI_Info_dup(info,newinfo,ierror)
INTEGER:: info
INTEGER:: newinfo
INTEGER:: ierror
END SUBROUTINE MPI_Info_dup

SUBROUTINE MPI_Info_free(info,ierror)
INTEGER:: info
INTEGER:: ierror
END SUBROUTINE MPI_Info_free

SUBROUTINE MPI_Info_get_nkeys(info,nkeys,ierror)
INTEGER:: info
INTEGER:: nkeys
INTEGER:: ierror
END SUBROUTINE MPI_Info_get_nkeys

SUBROUTINE MPI_Request_get_status(request,flag,status,ierror)
USE MPI_CONSTANTS
INTEGER:: request
LOGICAL:: flag
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: ierror
END SUBROUTINE MPI_Request_get_status

SUBROUTINE MPI_Type_create_hvector(count,blocklength,stride,oldtype,newtype,ierror)
USE MPI_CONSTANTS 
INTEGER:: count
INTEGER:: blocklength
INTEGER(KIND=MPI_ADDRESS_KIND):: stride
INTEGER:: oldtype
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_create_hvector

SUBROUTINE MPI_Type_create_resized(oldtype,lb,extent,newtype,ierror)
USE MPI_CONSTANTS 
INTEGER:: oldtype
INTEGER(KIND=MPI_ADDRESS_KIND):: lb
INTEGER(KIND=MPI_ADDRESS_KIND):: extent
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_create_resized

SUBROUTINE MPI_Type_get_extent(datatype,lb,extent,ierror)
USE MPI_CONSTANTS 
INTEGER:: datatype
INTEGER(KIND=MPI_ADDRESS_KIND):: lb
INTEGER(KIND=MPI_ADDRESS_KIND):: extent
INTEGER:: ierror
END SUBROUTINE MPI_Type_get_extent

SUBROUTINE MPI_Type_get_true_extent(datatype,true_lb,true_extent,ierror)
USE MPI_CONSTANTS 
INTEGER:: datatype
INTEGER(KIND=MPI_ADDRESS_KIND):: true_lb
INTEGER(KIND=MPI_ADDRESS_KIND):: true_extent
INTEGER:: ierror
END SUBROUTINE MPI_Type_get_true_extent

!SUBROUTINE MPI_Win_create_errhandler(win_errhandler_fn,errhandler,ierror)
!EXTERNAL:: win_errhandler_fn
!INTEGER:: errhandler
!INTEGER:: ierror
!END SUBROUTINE MPI_Win_create_errhandler

SUBROUTINE MPI_Win_get_errhandler(win,errhandler,ierror)
INTEGER:: win
INTEGER:: errhandler
INTEGER:: ierror
END SUBROUTINE MPI_Win_get_errhandler

SUBROUTINE MPI_Win_set_errhandler(win,errhandler,ierror)
INTEGER:: win
INTEGER:: errhandler
INTEGER:: ierror
END SUBROUTINE MPI_Win_set_errhandler

SUBROUTINE MPI_Type_create_f90_integer(range,newtype,ierror)
INTEGER:: range
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_create_f90_integer

SUBROUTINE MPI_Type_create_f90_real(precision,range,newtype,ierror)
INTEGER:: precision
INTEGER:: range
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_create_f90_real

SUBROUTINE MPI_Type_create_f90_complex(precision,range,newtype,ierror)
INTEGER:: precision
INTEGER:: range
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_create_f90_complex

!SUBROUTINE MPI_Reduce_local(inbuf,inoutbuf,count,datatype,op,ierror)
!EXTERNAL:: inbuf
!EXTERNAL:: inoutbuf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: op
!INTEGER:: ierror
!END SUBROUTINE MPI_Reduce_local

SUBROUTINE MPI_Op_commutative(op,commute,ierror)
INTEGER:: op
INTEGER:: commute
INTEGER:: ierror
END SUBROUTINE MPI_Op_commutative

SUBROUTINE MPI_Dist_graph_neighbors_count(comm,indegree,outdegree,weighted,ierror)
INTEGER:: comm
INTEGER:: indegree
INTEGER:: outdegree
LOGICAL:: weighted
INTEGER:: ierror
END SUBROUTINE MPI_Dist_graph_neighbors_count

SUBROUTINE MPI_Improbe(source,tag,comm,flag,message,status,ierror)
USE MPI_CONSTANTS
INTEGER:: source
INTEGER:: tag
INTEGER:: comm
LOGICAL:: flag
INTEGER:: message
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: ierror
END SUBROUTINE MPI_Improbe

!SUBROUTINE MPI_Imrecv(buf,count,datatype,message,request,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: message
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Imrecv

SUBROUTINE MPI_Mprobe(source,tag,comm,message,status,ierror)
USE MPI_CONSTANTS
INTEGER:: source
INTEGER:: tag
INTEGER:: comm
INTEGER:: message
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: ierror
END SUBROUTINE MPI_Mprobe

!SUBROUTINE MPI_Mrecv(buf,count,datatype,message,status,ierror)
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: message
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_Mrecv

SUBROUTINE MPI_Comm_idup(comm,newcomm,request,ierror)
INTEGER:: comm
INTEGER:: newcomm
INTEGER:: request
INTEGER:: ierror
END SUBROUTINE MPI_Comm_idup

SUBROUTINE MPI_Ibarrier(comm,request,ierror)
INTEGER:: comm
INTEGER:: request
INTEGER:: ierror
END SUBROUTINE MPI_Ibarrier

!SUBROUTINE MPI_Ibcast(buffer,count,datatype,root,comm,request,ierror)
!EXTERNAL:: buffer
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: root
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ibcast

!SUBROUTINE MPI_Igather(sendbuf,sendcount,sendtype,recvbuf,recvcount,recvtype,root,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: root
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Igather

!SUBROUTINE MPI_Iscatter(sendbuf,sendcount,sendtype,recvbuf,recvcount,recvtype,root,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: root
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Iscatter

!SUBROUTINE MPI_Iallgather(sendbuf,sendcount,sendtype,recvbuf,recvcount,recvtype,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Iallgather

!SUBROUTINE MPI_Ialltoall(sendbuf,sendcount,sendtype,recvbuf,recvcount,recvtype,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ialltoall

!SUBROUTINE MPI_Ireduce(sendbuf,recvbuf,count,datatype,op,root,comm,request,ierror)
!EXTERNAL:: sendbuf
!EXTERNAL:: recvbuf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: op
!INTEGER:: root
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ireduce
!
!SUBROUTINE MPI_Iallreduce(sendbuf,recvbuf,count,datatype,op,comm,request,ierror)
!EXTERNAL:: sendbuf
!EXTERNAL:: recvbuf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: op
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Iallreduce
!
!SUBROUTINE MPI_Ireduce_scatter_block(sendbuf,recvbuf,recvcount,datatype,op,comm,request,ierror)
!EXTERNAL:: sendbuf
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: datatype
!INTEGER:: op
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ireduce_scatter_block
!
!SUBROUTINE MPI_Iscan(sendbuf,recvbuf,count,datatype,op,comm,request,ierror)
!EXTERNAL:: sendbuf
!EXTERNAL:: recvbuf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: op
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Iscan
!
!SUBROUTINE MPI_Iexscan(sendbuf,recvbuf,count,datatype,op,comm,request,ierror)
!EXTERNAL:: sendbuf
!EXTERNAL:: recvbuf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: op
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Iexscan
!
!SUBROUTINE MPI_Ineighbor_allgather(sendbuf,sendcount,sendtype,recvbuf,recvcount,recvtype,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ineighbor_allgather
!
!SUBROUTINE MPI_Ineighbor_alltoall(sendbuf,sendcount,sendtype,recvbuf,recvcount,recvtype,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ineighbor_alltoall
!
!SUBROUTINE MPI_Neighbor_allgather(sendbuf,sendcount,sendtype,recvbuf,recvcount,recvtype,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Neighbor_allgather
!
!SUBROUTINE MPI_Neighbor_alltoall(sendbuf,sendcount,sendtype,recvbuf,recvcount,recvtype,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Neighbor_alltoall

SUBROUTINE MPI_Comm_split_type(comm,split_type,key,info,newcomm,ierror)
INTEGER:: comm
INTEGER:: split_type
INTEGER:: key
INTEGER:: info
INTEGER:: newcomm
INTEGER:: ierror
END SUBROUTINE MPI_Comm_split_type

SUBROUTINE MPI_Get_elements_x(status,datatype,count,ierror)
USE MPI_CONSTANTS
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: datatype
INTEGER(KIND=MPI_COUNT_KIND):: count
INTEGER:: ierror
END SUBROUTINE MPI_Get_elements_x

SUBROUTINE MPI_Status_set_elements_x(status,datatype,count,ierror)
USE MPI_CONSTANTS
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: datatype
INTEGER(KIND=MPI_COUNT_KIND):: count
INTEGER:: ierror
END SUBROUTINE MPI_Status_set_elements_x

SUBROUTINE MPI_Type_get_extent_x(datatype,lb,extent,ierror)
USE MPI_CONSTANTS 
INTEGER:: datatype
INTEGER(KIND=MPI_ADDRESS_KIND):: lb(*)
INTEGER(KIND=MPI_ADDRESS_KIND):: extent
INTEGER:: ierror
END SUBROUTINE MPI_Type_get_extent_x

SUBROUTINE MPI_Type_get_true_extent_x(datatype,lb,extent,ierror)
USE MPI_CONSTANTS 
INTEGER:: datatype
INTEGER(KIND=MPI_ADDRESS_KIND):: lb
INTEGER(KIND=MPI_ADDRESS_KIND):: extent
INTEGER:: ierror
END SUBROUTINE MPI_Type_get_true_extent_x

SUBROUTINE MPI_Type_size_x(datatype,size,ierror)
USE MPI_CONSTANTS 
INTEGER:: datatype
INTEGER(KIND=MPI_COUNT_KIND):: size
INTEGER:: ierror
END SUBROUTINE MPI_Type_size_x

SUBROUTINE MPI_Comm_create_group(comm,group,tag,newcomm,ierror)
INTEGER:: comm
INTEGER:: group
INTEGER:: tag
INTEGER:: newcomm
INTEGER:: ierror
END SUBROUTINE MPI_Comm_create_group

SUBROUTINE MPI_File_close(fh,ierror)
INTEGER:: fh
INTEGER:: ierror
END SUBROUTINE MPI_File_close

SUBROUTINE MPI_File_set_size(fh,size,ierror)
USE MPI_CONSTANTS 
INTEGER:: fh
INTEGER(KIND=MPI_OFFSET_KIND):: size
INTEGER:: ierror
END SUBROUTINE MPI_File_set_size

SUBROUTINE MPI_File_preallocate(fh,size,ierror)
USE MPI_CONSTANTS 
INTEGER:: fh
INTEGER(KIND=MPI_OFFSET_KIND):: size
INTEGER:: ierror
END SUBROUTINE MPI_File_preallocate

SUBROUTINE MPI_File_get_size(fh,size,ierror)
USE MPI_CONSTANTS 
INTEGER:: fh
INTEGER(KIND=MPI_OFFSET_KIND):: size
INTEGER:: ierror
END SUBROUTINE MPI_File_get_size

SUBROUTINE MPI_File_get_group(fh,group,ierror)
INTEGER:: fh
INTEGER:: group
INTEGER:: ierror
END SUBROUTINE MPI_File_get_group

SUBROUTINE MPI_File_get_amode(fh,amode,ierror)
INTEGER:: fh
INTEGER:: amode
INTEGER:: ierror
END SUBROUTINE MPI_File_get_amode

SUBROUTINE MPI_File_set_info(fh,info,ierror)
INTEGER:: fh
INTEGER:: info
INTEGER:: ierror
END SUBROUTINE MPI_File_set_info

SUBROUTINE MPI_File_get_info(fh,info_used,ierror)
INTEGER:: fh
INTEGER:: info_used
INTEGER:: ierror
END SUBROUTINE MPI_File_get_info

!SUBROUTINE MPI_File_read_at(fh,offset,buf,count,datatype,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_read_at
!
!SUBROUTINE MPI_File_read_at_all(fh,offset, buf,count,datatype,status,ierror)
!INTEGER:: fh
!EXTERNAL::  buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_read_at_all
!
!SUBROUTINE MPI_File_write_at(fh,offset, buf,count,datatype,status,ierror)
!INTEGER:: fh
!EXTERNAL::  buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_write_at
!
!SUBROUTINE MPI_File_write_at_all(fh,offset,buf,count,datatype,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_write_at_all
!
!SUBROUTINE MPI_File_iread_at(fh,offset,buf,count,datatype,request,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_File_iread_at
!
!SUBROUTINE MPI_File_iwrite_at(fh,offset,buf,count,datatype,request,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_File_iwrite_at
!
!SUBROUTINE MPI_File_read(fh,buf,count,datatype,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_read
!
!SUBROUTINE MPI_File_read_all(fh,buf,count,datatype,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_read_all
!
!SUBROUTINE MPI_File_write(fh,buf,count,datatype,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_write
!
!SUBROUTINE MPI_File_write_all(fh,buf,count,datatype,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_write_all
!
!SUBROUTINE MPI_File_iread(fh,buf,count,datatype,request,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_File_iread
!
!SUBROUTINE MPI_File_iwrite(fh,buf,count,datatype,request,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_File_iwrite

SUBROUTINE MPI_File_seek(fh,offset,whence,ierror)
USE MPI_CONSTANTS 
INTEGER:: fh
INTEGER(KIND=MPI_OFFSET_KIND):: offset
INTEGER:: whence
INTEGER:: ierror
END SUBROUTINE MPI_File_seek

SUBROUTINE MPI_File_get_position(fh,offset,ierror)
USE MPI_CONSTANTS 
INTEGER:: fh
INTEGER(KIND=MPI_OFFSET_KIND):: offset
INTEGER:: ierror
END SUBROUTINE MPI_File_get_position

SUBROUTINE MPI_File_get_byte_offset(fh,offset,disp,ierror)
USE MPI_CONSTANTS 
INTEGER:: fh
INTEGER(KIND=MPI_OFFSET_KIND):: offset, disp
INTEGER:: ierror
END SUBROUTINE MPI_File_get_byte_offset

!SUBROUTINE MPI_File_read_shared(fh,buf,count,datatype,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_read_shared
!
!SUBROUTINE MPI_File_write_shared(fh,buf,count,datatype,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_write_shared
!
!SUBROUTINE MPI_File_iread_shared(fh,buf,count,datatype,request,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_File_iread_shared
!
!SUBROUTINE MPI_File_iwrite_shared(fh,buf,count,datatype,request,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_File_iwrite_shared
!
!SUBROUTINE MPI_File_read_ordered(fh,buf,count,datatype,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_read_ordered
!
!SUBROUTINE MPI_File_write_ordered(fh,buf,count,datatype,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_write_ordered

SUBROUTINE MPI_File_seek_shared(fh,offset,whence,ierror)
USE MPI_CONSTANTS 
INTEGER:: fh
INTEGER(KIND=MPI_OFFSET_KIND):: offset
INTEGER:: whence
INTEGER:: ierror
END SUBROUTINE MPI_File_seek_shared

SUBROUTINE MPI_File_get_position_shared(fh,offset,ierror)
USE MPI_CONSTANTS 
INTEGER:: fh
INTEGER(KIND=MPI_OFFSET_KIND):: offset
INTEGER:: ierror
END SUBROUTINE MPI_File_get_position_shared

!SUBROUTINE MPI_File_read_at_all_begin(fh,offset,buf,count,datatype,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: ierror
!END SUBROUTINE MPI_File_read_at_all_begin

!SUBROUTINE MPI_File_read_at_all_end(fh,buf,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_read_at_all_end
!
!SUBROUTINE MPI_File_write_at_all_begin(fh,offset,buf,count,datatype,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: ierror
!END SUBROUTINE MPI_File_write_at_all_begin
!
!SUBROUTINE MPI_File_write_at_all_end(fh,buf,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_write_at_all_end
!
!SUBROUTINE MPI_File_read_all_begin(fh,buf,count,datatype,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: ierror
!END SUBROUTINE MPI_File_read_all_begin
!
!SUBROUTINE MPI_File_read_all_end(fh,buf,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_read_all_end
!
!SUBROUTINE MPI_File_write_all_begin(fh,buf,count,datatype,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: ierror
!END SUBROUTINE MPI_File_write_all_begin
!
!SUBROUTINE MPI_File_write_all_end(fh,buf,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_write_all_end
!
!SUBROUTINE MPI_File_read_ordered_begin(fh,buf,count,datatype,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: ierror
!END SUBROUTINE MPI_File_read_ordered_begin
!
!SUBROUTINE MPI_File_read_ordered_end(fh,buf,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_read_ordered_end
!
!SUBROUTINE MPI_File_write_ordered_begin(fh,buf,count,datatype,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: ierror
!END SUBROUTINE MPI_File_write_ordered_begin
!
!SUBROUTINE MPI_File_write_ordered_end(fh,buf,status,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: status
!INTEGER:: ierror
!END SUBROUTINE MPI_File_write_ordered_end

SUBROUTINE MPI_File_get_type_extent(fh,datatype,extent,ierror)
USE MPI_CONSTANTS 
INTEGER:: fh
INTEGER:: datatype
INTEGER(KIND=MPI_ADDRESS_KIND):: extent
INTEGER:: ierror
END SUBROUTINE MPI_File_get_type_extent

!SUBROUTINE MPI_Register_datarep(datarep,read_conversion_fn,write_conversion_fn,dtype_file_extent_fn,extra_state,ierror)
!CHARACTER:: datarep
!EXTERNAL:: read_conversion_fn
!EXTERNAL:: write_conversion_fn
!EXTERNAL:: dtype_file_extent_fn
!EXTERNAL:: extra_state
!INTEGER:: ierror
!END SUBROUTINE MPI_Register_datarep

SUBROUTINE MPI_File_set_atomicity(fh,flag,ierror)
INTEGER:: fh
INTEGER:: flag
INTEGER:: ierror
END SUBROUTINE MPI_File_set_atomicity

SUBROUTINE MPI_File_get_atomicity(fh,flag,ierror)
INTEGER:: fh
INTEGER:: flag
INTEGER:: ierror
END SUBROUTINE MPI_File_get_atomicity

SUBROUTINE MPI_File_sync(fh,ierror)
INTEGER:: fh
INTEGER:: ierror
END SUBROUTINE MPI_File_sync

FUNCTION MPI_Wtime()
DOUBLE PRECISION:: MPI_Wtime
END FUNCTION MPI_Wtime

FUNCTION MPI_Wtick()
DOUBLE PRECISION:: MPI_Wtick
END FUNCTION MPI_Wtick

SUBROUTINE MPI_Finalize(ierror)
INTEGER:: ierror
END SUBROUTINE MPI_Finalize

SUBROUTINE MPI_Waitany(count,array_of_requests,indx,status,ierror)
USE MPI_CONSTANTS
INTEGER:: count
INTEGER:: array_of_requests(*)
INTEGER:: indx
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: ierror
END SUBROUTINE MPI_Waitany

SUBROUTINE MPI_Testany(count,array_of_requests,indx,flag,status,ierror)
USE MPI_CONSTANTS
INTEGER:: count
INTEGER:: array_of_requests(count)
INTEGER:: indx
LOGICAL:: flag
INTEGER:: status(MPI_STATUS_SIZE)
INTEGER:: ierror
END SUBROUTINE MPI_Testany

SUBROUTINE MPI_Waitall(count,array_of_requests,array_of_statuses,ierror)
USE MPI_CONSTANTS
INTEGER:: count
INTEGER:: array_of_requests(*)
INTEGER:: array_of_statuses(MPI_STATUS_SIZE,*)
INTEGER:: ierror
END SUBROUTINE MPI_Waitall

SUBROUTINE MPI_Testall(count,array_of_requests,flag,array_of_statuses,ierror)
USE MPI_CONSTANTS
INTEGER:: count
INTEGER:: array_of_requests(*)
LOGICAL:: flag
INTEGER:: array_of_statuses(MPI_STATUS_SIZE,*)
INTEGER:: ierror
END SUBROUTINE MPI_Testall

SUBROUTINE MPI_Waitsome(incount,array_of_requests,outcount,array_of_indices,array_of_statuses,ierror)
USE MPI_CONSTANTS 
INTEGER:: incount
INTEGER:: array_of_requests(*)
INTEGER:: outcount
INTEGER:: array_of_indices(*)
INTEGER:: array_of_statuses(MPI_STATUS_SIZE,*)
INTEGER:: ierror
END SUBROUTINE MPI_Waitsome

SUBROUTINE MPI_Testsome(incount,array_of_requests,outcount,array_of_indices,array_of_statuses,ierror)
USE MPI_CONSTANTS
INTEGER:: incount
INTEGER:: array_of_requests(*)
INTEGER:: outcount
INTEGER:: array_of_indices(*)
INTEGER:: array_of_statuses(MPI_STATUS_SIZE,*)
INTEGER:: ierror
END SUBROUTINE MPI_Testsome

SUBROUTINE MPI_Startall(count,array_of_requests,ierror)
INTEGER:: count
INTEGER:: array_of_requests(*)
INTEGER:: ierror
END SUBROUTINE MPI_Startall

!SUBROUTINE MPI_Alltoallw(sendbuf,sendcounts,sdispls,sendtypes,recvbuf,recvcounts,rdispls,recvtypes,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcounts
!INTEGER:: sdispls
!INTEGER:: sendtypes
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: rdispls
!INTEGER:: recvtypes
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Alltoallw
!
!SUBROUTINE MPI_Reduce_scatter(sendbuf,recvbuf,recvcounts,datatype,op,comm,ierror)
!EXTERNAL:: sendbuf
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: datatype
!INTEGER:: op
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Reduce_scatter

SUBROUTINE MPI_Group_translate_ranks(group1,n,ranks1,group2,ranks2,ierror)
INTEGER:: group1
INTEGER:: n
INTEGER:: ranks1(*)
INTEGER:: group2
INTEGER:: ranks2(*)
INTEGER:: ierror
END SUBROUTINE MPI_Group_translate_ranks

SUBROUTINE MPI_Group_incl(group,n,ranks,newgroup,ierror)
INTEGER:: group
INTEGER:: n
INTEGER:: ranks(*)
INTEGER:: newgroup
INTEGER:: ierror
END SUBROUTINE MPI_Group_incl

SUBROUTINE MPI_Group_excl(group,n,ranks,newgroup,ierror)
INTEGER:: group
INTEGER:: n
INTEGER:: ranks(n)
INTEGER:: newgroup
INTEGER:: ierror
END SUBROUTINE MPI_Group_excl

SUBROUTINE MPI_Group_range_incl(group,n,ranges,newgroup,ierror)
INTEGER:: group
INTEGER:: n
INTEGER:: ranges(3,*)
INTEGER:: newgroup
INTEGER:: ierror
END SUBROUTINE MPI_Group_range_incl

SUBROUTINE MPI_Group_range_excl(group,n,ranges,newgroup,ierror)
INTEGER:: group
INTEGER:: n
INTEGER:: ranges(3,*)
INTEGER:: newgroup
INTEGER:: ierror
END SUBROUTINE MPI_Group_range_excl

SUBROUTINE MPI_Cart_create(comm_old,ndims,dims,periods,reorder,comm_cart,ierror)
INTEGER:: comm_old
INTEGER:: ndims
INTEGER:: dims(*)
LOGICAL:: periods(*)
LOGICAL:: reorder
INTEGER:: comm_cart
INTEGER:: ierror
END SUBROUTINE MPI_Cart_create

SUBROUTINE MPI_Dims_create(nnodes,ndims,dims,ierror)
INTEGER:: nnodes
INTEGER:: ndims
INTEGER:: dims(*)
INTEGER:: ierror
END SUBROUTINE MPI_Dims_create

SUBROUTINE MPI_Graph_create(comm_old,nnodes,indx,edges,reorder,comm_graph,ierror)
INTEGER:: comm_old
INTEGER:: nnodes
INTEGER:: indx(*)
INTEGER:: edges(*)
LOGICAL:: reorder
INTEGER:: comm_graph
INTEGER:: ierror
END SUBROUTINE MPI_Graph_create

SUBROUTINE MPI_Graph_get(comm,maxindex,maxedges,indx,edges,ierror)
INTEGER:: comm
INTEGER:: maxindex
INTEGER:: maxedges
INTEGER:: indx(*)
INTEGER:: edges(*)
INTEGER:: ierror
END SUBROUTINE MPI_Graph_get

SUBROUTINE MPI_Cart_get(comm,maxdims,dims,periods,coords,ierror)
INTEGER:: comm
INTEGER:: maxdims
INTEGER:: dims(*)
LOGICAL:: periods(*)
INTEGER:: coords(*)
INTEGER:: ierror
END SUBROUTINE MPI_Cart_get

SUBROUTINE MPI_Cart_rank(comm,coords,rank,ierror)
INTEGER:: comm
INTEGER:: coords
INTEGER:: rank
INTEGER:: ierror
END SUBROUTINE MPI_Cart_rank

SUBROUTINE MPI_Cart_coords(comm,rank,maxdims,coords,ierror)
INTEGER:: comm
INTEGER:: rank
INTEGER:: maxdims
INTEGER:: coords(*)
INTEGER:: ierror
END SUBROUTINE MPI_Cart_coords

SUBROUTINE MPI_Graph_neighbors(comm,rank,maxneighbors,neighbors,ierror)
INTEGER:: comm
INTEGER:: rank
INTEGER:: maxneighbors
INTEGER:: neighbors(*)
INTEGER:: ierror
END SUBROUTINE MPI_Graph_neighbors

SUBROUTINE MPI_Cart_sub(comm,remain_dims,newcomm,ierror)
INTEGER:: comm
INTEGER:: remain_dims
INTEGER:: newcomm
INTEGER:: ierror
END SUBROUTINE MPI_Cart_sub

SUBROUTINE MPI_Cart_map(comm,ndims,dims,periods,newrank,ierror)
INTEGER:: comm
INTEGER:: ndims
INTEGER:: dims(*)
LOGICAL:: periods(*)
INTEGER:: newrank
INTEGER:: ierror
END SUBROUTINE MPI_Cart_map

SUBROUTINE MPI_Graph_map(comm,nnodes,indx,edges,newrank,ierror)
INTEGER:: comm
INTEGER:: nnodes
INTEGER:: indx(*)
INTEGER:: edges(*)
INTEGER:: newrank
INTEGER:: ierror
END SUBROUTINE MPI_Graph_map

SUBROUTINE MPI_Comm_spawn(command,argv,maxprocs,info,root,comm,intercomm,array_of_errcodes,ierror)
CHARACTER(LEN=*):: command
CHARACTER(LEN=*):: argv
INTEGER:: maxprocs
INTEGER:: info
INTEGER:: root
INTEGER:: comm
INTEGER:: intercomm
INTEGER:: array_of_errcodes(*)
INTEGER:: ierror
END SUBROUTINE MPI_Comm_spawn

SUBROUTINE MPI_Comm_spawn_multiple(count,array_of_commands,array_of_argv,array_of_maxprocs,array_of_info,root,comm,intercomm,array_of_errcodes,ierror)
INTEGER:: count
CHARACTER(len=*):: array_of_commands(*)
CHARACTER(len=*):: array_of_argv(count, *)
INTEGER:: array_of_maxprocs(*)
INTEGER:: array_of_info(*)
INTEGER:: root
INTEGER:: comm
INTEGER:: intercomm
INTEGER:: array_of_errcodes(*)
INTEGER:: ierror
END SUBROUTINE MPI_Comm_spawn_multiple

SUBROUTINE MPI_Type_get_contents(datatype,max_integers,max_addresses,max_datatypes,array_of_integers,array_of_addresses,array_of_datatypes,ierror)
USE MPI_CONSTANTS 
INTEGER:: datatype
INTEGER:: max_integers
INTEGER:: max_addresses
INTEGER:: max_datatypes
INTEGER:: array_of_integers(*)
INTEGER(KIND=MPI_ADDRESS_KIND):: array_of_addresses(*)
INTEGER:: array_of_datatypes(*)
INTEGER:: ierror
END SUBROUTINE MPI_Type_get_contents

!SUBROUTINE MPI_Pack_external(datarep,inbuf,incount,datatype,outbuf,outsize,position,ierror)
!EXTERNAL:: inbuf
!INTEGER:: incount
!INTEGER:: datatype
!EXTERNAL:: outbuf
!INTEGER:: outsize
!INTEGER:: position
!INTEGER:: ierror
!END SUBROUTINE MPI_Pack_external

SUBROUTINE MPI_Pack_external_size(datarep,incount,datatype,size,ierror)
USE MPI_CONSTANTS 
CHARACTER(len=*)::  datarep
INTEGER:: incount
INTEGER:: datatype
INTEGER(KIND=MPI_ADDRESS_KIND):: size
INTEGER:: ierror
END SUBROUTINE MPI_Pack_external_size

SUBROUTINE MPI_Type_create_darray(size,rank,ndims,array_of_gsizes,array_of_distribs,array_of_dargs,array_of_psizes,order,oldtype,newtype,ierror)
INTEGER:: size
INTEGER:: rank
INTEGER:: ndims
INTEGER:: array_of_gsizes(*)
INTEGER:: array_of_distribs(*)
INTEGER:: array_of_dargs(*)
INTEGER:: array_of_psizes(*)
INTEGER:: order
INTEGER:: oldtype
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_create_darray

SUBROUTINE MPI_Type_create_hindexed(count,array_of_blocklengths,array_of_displacements,oldtype,newtype,ierror)
INTEGER:: count
INTEGER:: array_of_blocklengths(*)
INTEGER:: array_of_displacements(*)
INTEGER:: oldtype
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_create_hindexed

SUBROUTINE MPI_Type_create_indexed_block(count,blocklength,array_of_displacements,oldtype,newtype,ierror)
INTEGER:: count
INTEGER:: blocklength
INTEGER:: array_of_displacements(*)
INTEGER:: oldtype
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_create_indexed_block

SUBROUTINE MPI_Type_create_hindexed_block(count,blocklength,array_of_displacements,oldtype,newtype,ierror)
INTEGER:: count
INTEGER:: blocklength
INTEGER:: array_of_displacements(*)
INTEGER:: oldtype
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_create_hindexed_block

SUBROUTINE MPI_Type_create_struct(count,array_of_blocklengths,array_of_displacements,array_of_types,newtype,ierror)
INTEGER:: count
INTEGER:: array_of_blocklengths(*)
INTEGER:: array_of_displacements(*)
INTEGER:: array_of_types(*)
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_create_struct

SUBROUTINE MPI_Type_create_subarray(ndims,array_of_sizes,array_of_subsizes,array_of_starts,order,oldtype,newtype,ierror)
INTEGER:: ndims
INTEGER:: array_of_sizes(*)
INTEGER:: array_of_subsizes(*)
INTEGER:: array_of_starts(*)
INTEGER:: order
INTEGER:: oldtype
INTEGER:: newtype
INTEGER:: ierror
END SUBROUTINE MPI_Type_create_subarray

!SUBROUTINE MPI_Unpack_external(datarep,inbuf,insize,position,outbuf,outcount,datatype,ierror)
!EXTERNAL:: inbuf
!INTEGER:: insize
!INTEGER:: position
!EXTERNAL:: outbuf
!INTEGER:: outcount
!INTEGER:: datatype
!INTEGER:: ierror
!END SUBROUTINE MPI_Unpack_external

SUBROUTINE MPI_Dist_graph_create_adjacent(comm_old,indegree,sources,sourceweights,outdegree,destinations,destweights,info,reorder,comm_dist_graph,ierror)
INTEGER:: comm_old
INTEGER:: indegree
INTEGER:: sources(*)
INTEGER:: sourceweights(*)
INTEGER:: outdegree
INTEGER:: destinations(*)
INTEGER:: destweights(*)
INTEGER:: info
LOGICAL:: reorder
INTEGER:: comm_dist_graph
INTEGER:: ierror
END SUBROUTINE MPI_Dist_graph_create_adjacent

SUBROUTINE MPI_Dist_graph_create(comm_old,n,sources,degrees,destinations,weights,info,reorder,comm_dist_graph,ierror)
INTEGER:: comm_old
INTEGER:: n
INTEGER:: sources(*)
INTEGER:: degrees(*)
INTEGER:: destinations(*)
INTEGER:: weights
INTEGER:: info
LOGICAL:: reorder
INTEGER:: comm_dist_graph
INTEGER:: ierror
END SUBROUTINE MPI_Dist_graph_create

SUBROUTINE MPI_Dist_graph_neighbors(comm,maxindegree,sources,sourceweights,maxoutdegree,destinations,destweights,ierror)
INTEGER:: comm
INTEGER:: maxindegree
INTEGER:: sources(*)
INTEGER:: sourceweights(*)
INTEGER:: maxoutdegree
INTEGER:: destinations(*)
INTEGER:: destweights(*)
INTEGER:: ierror
END SUBROUTINE MPI_Dist_graph_neighbors

!SUBROUTINE MPI_Igatherv(sendbuf,sendcount,sendtype,recvbuf,recvcounts,displs,recvtype,root,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: displs
!INTEGER:: recvtype
!INTEGER:: root
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Igatherv
!
!SUBROUTINE MPI_Iscatterv(sendbuf,sendcounts,displs,sendtype,recvbuf,recvcount,recvtype,root,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcounts
!INTEGER:: displs
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcount
!INTEGER:: recvtype
!INTEGER:: root
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Iscatterv
!
!SUBROUTINE MPI_Iallgatherv(sendbuf,sendcount,sendtype,recvbuf,recvcounts,displs,recvtype,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: displs
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Iallgatherv
!
!SUBROUTINE MPI_Ialltoallv(sendbuf,sendcounts,sdispls,sendtype,recvbuf,recvcounts,rdispls,recvtype,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcounts
!INTEGER:: sdispls
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: rdispls
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ialltoallv
!
!SUBROUTINE MPI_Ialltoallw(sendbuf,sendcounts,sdispls,sendtypes,recvbuf,recvcounts,rdispls,recvtypes,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcounts
!INTEGER:: sdispls
!INTEGER:: sendtypes(*)
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: rdispls
!INTEGER:: recvtypes(*)
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ialltoallw
!
!SUBROUTINE MPI_Ireduce_scatter(sendbuf,recvbuf,recvcounts,datatype,op,comm,request,ierror)
!EXTERNAL:: sendbuf
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: datatype
!INTEGER:: op
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ireduce_scatter
!
!SUBROUTINE MPI_Ineighbor_allgatherv(sendbuf,sendcount,sendtype,recvbuf,recvcounts,displs,recvtype,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: displs
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ineighbor_allgatherv
!
!SUBROUTINE MPI_Ineighbor_alltoallv(sendbuf,sendcounts,sdispls,sendtype,recvbuf,recvcounts,rdispls,recvtype,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcounts
!INTEGER:: sdispls
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: rdispls
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ineighbor_alltoallv
!
!SUBROUTINE MPI_Ineighbor_alltoallw(sendbuf,sendcounts,sdispls,sendtypes,recvbuf,recvcounts,rdispls,recvtypes,comm,request,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcounts
!INTEGER:: sdispls
!INTEGER:: sendtypes
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: rdispls
!INTEGER:: recvtypes
!INTEGER:: comm
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_Ineighbor_alltoallw
!
!SUBROUTINE MPI_Neighbor_allgatherv(sendbuf,sendcount,sendtype,recvbuf,recvcounts,displs,recvtype,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcount
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: displs
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Neighbor_allgatherv
!
!SUBROUTINE MPI_Neighbor_alltoallv(sendbuf,sendcounts,sdispls,sendtype,recvbuf,recvcounts,rdispls,recvtype,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcounts
!INTEGER:: sdispls
!INTEGER:: sendtype
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: rdispls
!INTEGER:: recvtype
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Neighbor_alltoallv
!
!SUBROUTINE MPI_Neighbor_alltoallw(sendbuf,sendcounts,sdispls,sendtypes,recvbuf,recvcounts,rdispls,recvtypes,comm,ierror)
!EXTERNAL:: sendbuf
!INTEGER:: sendcounts
!INTEGER:: sdispls
!INTEGER:: sendtypes(*)
!EXTERNAL:: recvbuf
!INTEGER:: recvcounts
!INTEGER:: rdispls
!INTEGER:: recvtypes(*)
!INTEGER:: comm
!INTEGER:: ierror
!END SUBROUTINE MPI_Neighbor_alltoallw
!
!SUBROUTINE MPI_File_iwrite_all(fh,buf,count,datatype,request,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_File_iwrite_all
!
!SUBROUTINE MPI_File_iwrite_at_all(fh,offset,buf,count,datatype,request,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_File_iwrite_at_all

FUNCTION MPI_Aint_add(base,disp,ierror)
USE MPI_CONSTANTS
INTEGER(KIND=MPI_ADDRESS_KIND):: MPI_Aint_add
INTEGER(KIND=MPI_ADDRESS_KIND):: base
INTEGER(KIND=MPI_ADDRESS_KIND):: disp
INTEGER:: ierror
END FUNCTION MPI_Aint_add

FUNCTION MPI_Aint_diff(addr1,addr2,ierror)
USE MPI_CONSTANTS
INTEGER(KIND=MPI_ADDRESS_KIND):: MPI_Aint_diff
INTEGER(KIND=MPI_ADDRESS_KIND):: addr1
INTEGER(KIND=MPI_ADDRESS_KIND):: addr2
INTEGER:: ierror
END FUNCTION MPI_Aint_diff

!SUBROUTINE MPI_File_iread_all(fh,buf,count,datatype,request,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_File_iread_all

SUBROUTINE MPI_Error_string(errorcode,string,resultlen,ierror)
INTEGER:: errorcode
CHARACTER(len=*):: string
INTEGER:: resultlen
INTEGER:: ierror
END SUBROUTINE MPI_Error_string

SUBROUTINE MPI_Get_processor_name(name,resultlen,ierror)
CHARACTER(len=*):: name
INTEGER:: resultlen
INTEGER:: ierror
END SUBROUTINE MPI_Get_processor_name

SUBROUTINE MPI_File_open(comm,filename,amode,info,fh,ierror)
INTEGER:: comm
CHARACTER(len=*):: filename
INTEGER:: amode
INTEGER:: info
INTEGER:: fh
INTEGER:: ierror
END SUBROUTINE MPI_File_open

SUBROUTINE MPI_File_set_view(fh,disp,etype,filetype,datarep,info,ierror)
USE MPI_CONSTANTS 
INTEGER:: fh
INTEGER(KIND=MPI_OFFSET_KIND):: disp
INTEGER:: etype
INTEGER:: filetype
CHARACTER(len=*):: datarep
INTEGER:: info
INTEGER:: ierror
END SUBROUTINE MPI_File_set_view

SUBROUTINE MPI_File_get_view(fh,disp,etype,filetype,datarep,ierror)
USE MPI_CONSTANTS 
INTEGER:: fh
INTEGER(KIND=MPI_OFFSET_KIND):: disp
INTEGER:: etype
INTEGER:: filetype
CHARACTER(len=*):: datarep
INTEGER:: ierror
END SUBROUTINE MPI_File_get_view

SUBROUTINE MPI_File_delete(filename,info,ierror)
CHARACTER(len=*):: filename
INTEGER:: info
INTEGER:: ierror
END SUBROUTINE MPI_File_delete

SUBROUTINE MPI_Info_delete(info,key,ierror)
INTEGER:: info
CHARACTER(len=*):: key
INTEGER:: ierror
END SUBROUTINE MPI_Info_delete

SUBROUTINE MPI_Info_get(info,key,valuelen,value,flag,ierror)
INTEGER:: info
CHARACTER(len=*):: key
INTEGER:: valuelen
CHARACTER(len=*):: value
LOGICAL:: flag
INTEGER:: ierror
END SUBROUTINE MPI_Info_get

SUBROUTINE MPI_Info_get_nthkey(info,n,key,ierror)
INTEGER:: info
INTEGER:: n
CHARACTER(len=*):: key
INTEGER:: ierror
END SUBROUTINE MPI_Info_get_nthkey

SUBROUTINE MPI_Info_get_valuelen(info,key,valuelen,flag,ierror)
INTEGER:: info
CHARACTER(len=*):: key
INTEGER:: valuelen
LOGICAL:: flag
INTEGER:: ierror
END SUBROUTINE MPI_Info_get_valuelen

SUBROUTINE MPI_Info_set(info,key,value,ierror)
INTEGER:: info
CHARACTER(len=*):: key
CHARACTER(len=*):: value
INTEGER:: ierror
END SUBROUTINE MPI_Info_set

!SUBROUTINE MPI_File_iread_at_all(fh,offset,buf,count,datatype,request,ierror)
!INTEGER:: fh
!EXTERNAL:: buf
!INTEGER:: count
!INTEGER:: datatype
!INTEGER:: request
!INTEGER:: ierror
!END SUBROUTINE MPI_File_iread_at_all
END INTERFACE
END MODULE MPI_BASE
!Nombre de fonction ajoutee: 363
