/*
 *  Copyright (c) 2012-2014, Bruno Levy
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *  this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 *  * Neither the name of the ALICE Project-Team nor the names of its
 *  contributors may be used to endorse or promote products derived from this
 *  software without specific prior written permission.
 * 
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 *  If you modify this software, you should include a notice giving the
 *  name of the person performing the modification, the date of modification,
 *  and the reason for such modification.
 *
 *  Contact: Bruno Levy
 *
 *     Bruno.Levy@inria.fr
 *     http://www.loria.fr/~levy
 *
 *     ALICE Project
 *     LORIA, INRIA Lorraine, 
 *     Campus Scientifique, BP 239
 *     54506 VANDOEUVRE LES NANCY CEDEX 
 *     FRANCE
 *
 */

#ifndef GEOGRAM_DELAUNAY_DELAUNAY_TRIANGLE
#define GEOGRAM_DELAUNAY_DELAUNAY_TRIANGLE

/**
 * \file geogram/delaunay/delaunay_triangle.h
 * \brief Implementation of Delaunay in 2D using the triangle library
 *  by Jonathan Shewchuk.
 */

#ifdef GEOGRAM_WITH_TRIANGLE

#include <geogram/basic/common.h>
#include <geogram/delaunay/delaunay.h>

extern "C" {
#define REAL double
#define ANSI_DECLARATORS
#define VOID void    
#include <triangle.h>
}

namespace GEO {

    /**
     * \brief Implementation of Delaunay using Jonathan Shewchuk's triangle library.
     */
    class GEOGRAM_API DelaunayTriangle : public Delaunay {
    public:
        /**
         * \brief Creates a new DelaunayTriangle.
         * \details DelaunayTetgen triangulations are only supported for
         * dimension 2. If a different dimension is specified in the
         * constructor, a InvalidDimension exception is thrown.
         * \param[in] dimension dimension of the triangulation
         * \throw InvalidDimension This exception is thrown if dimension is
         * different than 2.
         */
        DelaunayTriangle(coord_index_t dimension = 2);

        /**
         * \copydoc Delaunay::set_vertices()
         */
        virtual void set_vertices(
            index_t nb_vertices, const double* vertices
        );

        /**
         * \brief DelaunayTriangle destructor.
         */
        virtual ~DelaunayTriangle();

    protected:
        struct triangulateio triangle_out_ ;
        struct triangulateio triangle_in_ ;
    };
}

#endif

#endif

