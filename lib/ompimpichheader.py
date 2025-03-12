#!/usr/bin/env python3
"""
OmpiMpichHeader module for generating Ompi-Mpich preload header files.
"""

import os
import re
from logging import getLogger
from logging.config import fileConfig
from ompiintelheader import OmpiIntelHeaderGenerator
from textoperator import function_to_delete

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class OmpiMpichHeaderGenerator(OmpiIntelHeaderGenerator):
    """
    OmpiMpichHeaderGenerator class for generating Ompi-Mpich preload header files.

    Attributes:
        app (str): Used in copy_files to select file names to copy.
        run (str): Used in copy_files to select file names to copy.

    Methods:
        _preload_exception_header_run_mpi_protoh: Applies exceptions for run_mpi_proto.h file.
        _generate_app_mpi_protoh: Override this method to prevent generation of the app_mpi_proto.h file.
        _generate_run_mpi_protoh: Generate the run_mpi_proto.h header file.
    """

    app = "openmpi"
    run = "mpich"

    def _preload_exception_header_run_mpi_protoh(self, text):
        """
        Applies exceptions for run_mpi_proto.h file.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        text = re.sub(r"A_MPI", r"R_MPI", text)
        text = re.sub(r"A_QMPI", r"R_QMPI", text)
        text = re.sub(r"A_PMPI", r"R_PMPI", text)
        list_to_delete = [
            "int R_MPI_Send",
            "int R_MPI_Get_count",
            "int R_MPI_Bsend",
            "int R_MPI_Ssend",
            "int R_MPI_Rsend",
            "int R_MPI_Isend",
            "int R_MPI_Ibsend",
            "int R_MPI_Issend",
            "int R_MPI_Irsend",
            "int R_MPI_Test_cancelled",
            "int R_MPI_Send_init",
            "int R_MPI_Bsend_init",
            "int R_MPI_Ssend_init",
            "int R_MPI_Rsend_init",
            "int R_MPI_Sendrecv",
            "int R_MPI_Type_indexed",
            "int R_MPI_Get_elements",
            "int R_MPI_Pack",
            "int R_MPI_Unpack",
            "int R_MPI_Gather",
            "int R_MPI_Gatherv",
            "int R_MPI_Scatter",
            "int R_MPI_Scatterv",
            "int R_MPI_Allgather",
            "int R_MPI_Allgatherv",
            "int R_MPI_Alltoall",
            "int R_MPI_Alltoallv",
            "int R_MPI_Exscan",
            "int R_MPI_Reduce",
            "int R_MPI_Allreduce",
            "int R_MPI_Scan",
            "int R_MPI_Close_port",
            "int R_MPI_Comm_accept",
            "int R_MPI_Comm_connect",
            "int R_MPI_Lookup_name",
            "int R_MPI_Publish_name",
            "int R_MPI_Unpublish_name",
            "int R_MPI_Accumulate",
            "int R_MPI_Put",
            "int R_MPI_Win_detach",
            "int R_MPI_Get_accumulate",
            "int R_MPI_Fetch_and_op",
            "int R_MPI_Compare_and_swap",
            "int R_MPI_Rput",
            "int R_MPI_Raccumulate",
            "int R_MPI_Rget_accumulate",
            "int R_MPI_Add_error_string",
            "int R_MPI_Comm_set_name",
            "int R_MPI_Type_set_name",
            "int R_MPI_Win_set_name",
            "int R_MPI_Get_address",
            "int R_MPI_Info_delete",
            "int R_MPI_Info_get",
            "int R_MPI_Info_get_valuelen",
            "int R_MPI_Info_set",
            "int R_MPI_Reduce_local",
            "int R_MPI_Reduce_scatter_block",
            "int R_MPI_Igather",
            "int R_MPI_Iscatter",
            "int R_MPI_Iallgather",
            "int R_MPI_Ialltoall",
            "int R_MPI_Ireduce",
            "int R_MPI_Iallreduce",
            "int R_MPI_Reduce_scatter_block",
            "int R_MPI_Iscan",
            "int R_MPI_Iexscan",
            "int R_MPI_Ineighbor_allgather",
            "int R_MPI_Ineighbor_alltoall",
            "int R_MPI_Neighbor_allgather",
            "int R_MPI_Neighbor_alltoall",
            "int R_MPI_Get_elements_x",
            "int R_MPI_T_cvar_write",
            "int R_MPI_Alltoallw",
            "int R_MPI_Reduce_scatter",
            "int R_MPI_Group_translate_ranks",
            "int R_MPI_Group_incl",
            "int R_MPI_Group_excl",
            "int R_MPI_Cart_create",
            "int R_MPI_Graph_create",
            "int R_MPI_Cart_rank",
            "int R_MPI_Cart_sub",
            "int R_MPI_Cart_map",
            "int R_MPI_Graph_map",
            "int R_MPI_Comm_spawn",
            "int R_MPI_Comm_spawn_multiple",
            "int R_MPI_Pack_external",
            "int R_MPI_Pack_external_size",
            "int R_MPI_Type_create_darray",
            "int R_MPI_Type_create_hindexed",
            "int R_MPI_Type_create_indexed_block",
            "int R_MPI_Type_create_hindexed_block",
            "int R_MPI_Type_create_struct",
            "int R_MPI_Type_create_subarray",
            "int R_MPI_Unpack_external",
            "int R_MPI_Dist_graph_create_adjacent",
            "int R_MPI_Dist_graph_create",
            "int R_MPI_Igatherv",
            "int R_MPI_Iscatterv",
            "int R_MPI_Iallgatherv",
            "int R_MPI_Ialltoallv",
            "int R_MPI_Ialltoallw",
            "int R_MPI_Ireduce_scatter",
            "int R_MPI_Ineighbor_allgatherv",
            "int R_MPI_Ineighbor_alltoallv",
            "int R_MPI_Ineighbor_alltoallw",
            "int R_MPI_Neighbor_allgatherv",
            "int R_MPI_Neighbor_alltoallv",
            "int R_MPI_Neighbor_alltoallw",
            "int R_MPI_T_category_get_index",
            "int R_MPI_T_cvar_get_index",
            "int R_MPI_T_pvar_get_index",
        ]
        for item in list_to_delete:
            text = function_to_delete(text, item)
        return text

    def _generate_app_mpi_protoh(self, gen_file):
        """
        Override this method to prevent generation of the app_mpi_proto.h file.
        """
        pass

    def _generate_run_mpi_protoh(self, gen_file):
        """
        Generate the run_mpi_proto.h header file.

        Args:
            gen_file (str): The path to the generated file.
        """
        if "4.2.0" == self.mpi_target_version["mpich"]:
            log.debug("Running _generate_run_mpi_protoh (IntelIntelGenerator)")
            with open(gen_file, "r", encoding="utf-8") as _file:
                _content = _file.read()
            _content = self._replace_mpi_with_rmpi(_content)
            _new_content = self._preload_exception_header_run_mpi_protoh(_content)
            with open(gen_file, "w", encoding="utf-8") as _file:
                _file.write(_new_content)
        else:
            pass
