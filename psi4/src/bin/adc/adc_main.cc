/*
 * @BEGIN LICENSE
 *
 * Psi4: an open-source quantum chemistry software package
 *
 * Copyright (c) 2007-2016 The Psi4 Developers.
 *
 * The copyrights for code used from other parties are included in
 * the corresponding files.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * @END LICENSE
 */


#include "psi4/src/lib/libciomr/libciomr.h"
#include "psi4/src/lib/liboptions/liboptions.h"
#include "psi4/include/psi4-dec.h"
#include "adc.h"

namespace psi{ namespace adc {

SharedWavefunction adc(SharedWavefunction ref_wfn, Options &options)
{
    tstart();

    outfile->Printf( "\n");
    outfile->Printf( "\t****************************************\n");
    outfile->Printf( "\t                 A D C                  \n");
    outfile->Printf( "\t An Algebraic-Diagrammatic Construction \n");
    outfile->Printf( "\t based on direct-product decomposition  \n");
    outfile->Printf( "\t             Masaaki Saitow             \n");
    outfile->Printf( "\t****************************************\n\n");


    //
    // I've never verified whether this Libtrans version works correctly with frozen orbitals. I first developed the ADC code with transqt2
    // module and implemented in the previous Psi3. Due to circumvent the handling of VVVV-typed ERIs (generated by transqt2 by default),
    // this code is completely rewrtten in order to be better suited for Libtrans library, more flexible than transqt2.
    //

    boost::shared_ptr<ADCWfn> adcwfn(new ADCWfn(ref_wfn, options));
    adcwfn->compute_energy();

    tstop();

    outfile->Printf( "\n");
    outfile->Printf( "  ∩==\n");
    outfile->Printf( "(: 3)))== kskkskkskksk         BOOOoooooOOOON!\n");
    outfile->Printf( "  ∪==\n");

    SharedWavefunction base_adcwfn = static_cast<SharedWavefunction>(adcwfn);
    return base_adcwfn;
}

}} // End Namespaces