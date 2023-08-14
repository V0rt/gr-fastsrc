/*
 * Copyright 2023 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(lfm_chirp.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(2d985214b6695ec3ce1974b9da793c95)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/fastsrc/lfm_chirp.h>
// pydoc.h is automatically generated in the build directory
#include <lfm_chirp_pydoc.h>

void bind_lfm_chirp(py::module& m)
{

    using lfm_chirp    = gr::fastsrc::lfm_chirp;


    py::class_<lfm_chirp, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<lfm_chirp>>(m, "lfm_chirp", D(lfm_chirp))

        .def(py::init(&lfm_chirp::make),
           D(lfm_chirp,make)
        )
        



        ;




}







