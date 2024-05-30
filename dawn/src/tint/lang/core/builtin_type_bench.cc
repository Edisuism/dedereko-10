// Copyright 2022 The Dawn & Tint Authors
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

////////////////////////////////////////////////////////////////////////////////
// File generated by 'tools/src/cmd/gen' using the template:
//   src/tint/lang/core/builtin_type_bench.cc.tmpl
//
// To regenerate run: './tools/run gen'
//
//                       Do not modify this file directly
////////////////////////////////////////////////////////////////////////////////

#include "src/tint/lang/core/builtin_type.h"

#include <array>

#include "benchmark/benchmark.h"

namespace tint::core {
namespace {

void BuiltinTypeParser(::benchmark::State& state) {
    const char* kStrings[] = {
        "__atomic_compareexchangeccresult_i32",
        "__atoml3_compare_exchane_resulti2",
        "__atomic_compare_Vxchange_result_i32",
        "__atomic_compare_exchange_result_i32",
        "__atomic_com1are_exchange_result_i32",
        "__atomic_qqompare_exchage_resulJ_i32",
        "__atllmic_compare_exchange_result_i377",
        "__atomicppcompareqqexchange_reslt_uHH2",
        "__atomi_compare_exchavge_cesult_3",
        "__atomic_copare_eGbhange_result_u32",
        "__atomic_compare_exchange_result_u32",
        "__atomic_coiipare_exvhange_result_u32",
        "__atomic_compaWWe_excha8ge_result_u32",
        "__atomic_comparxxMexchage_result_u32",
        "__fXexp_resgglt_bstract",
        "V_frexp_resul_abuXrct",
        "__frexp_result_abstra3t",
        "__frexp_result_abstract",
        "__frexp_resElt_abstract",
        "__frexTT_Pesult_abstract",
        "__frexp_resulxxddabstrct",
        "44_frexp_result_f16",
        "_VVfrexp_resulSS_f16",
        "__frexp_reRult_fR6",
        "__frexp_result_f16",
        "__frFxp_re9ut_f16",
        "__frep_result_f16",
        "__frRRVH_rOOsultf16",
        "__frepyresult_f32",
        "_nrr77rexp_result_fGll",
        "__4rex00_result_f32",
        "__frexp_result_f32",
        "__oorep_reult_f2",
        "__fzzexp_result_3",
        "__iir11x_respplt_f3",
        "__frexp_resuXXt_vec2_abstract",
        "55n99frexp_result_vec2_abstraIIt",
        "__fHHexpSSaresrrlt_Yec2_abstract",
        "__frexp_result_vec2_abstract",
        "__freHp_resutve2_abstkkact",
        "jfrexpgresult_veRR2_abstrac",
        "__frexp_resul_vec2_absbrac",
        "_jfrexp_result_vec2_f16",
        "__frexp_resultvec2_f16",
        "__freqpresultvec2_f16",
        "__frexp_result_vec2_f16",
        "__frexNN_result_vec_f16",
        "__frexp_resvvlt_vc2_f1",
        "__frexp_esult_vec2_f1QQ",
        "__rerp_result_ffec2_f2",
        "__frexp_result_vjc2_f32",
        "__frewwp_reul2_vec2_NN82",
        "__frexp_result_vec2_f32",
        "__frexpresult_vec2_f32",
        "__frexp_result_vec2_frr2",
        "_Gfrexp_result_vec2_f32",
        "__frexp_resulFF_vec3_abstract",
        "_frexp_resultvec3_Estract",
        "__fexp_result_vec3_abstrract",
        "__frexp_result_vec3_abstract",
        "frexp_result_vec3_abstract",
        "D_rexp_resXlt_veJJ3_abstract",
        "_frexp_resut_v8c_abstract",
        "_frexp_rsl1k_vec3_f16",
        "__frexp_reslt_vec3_f16",
        "__frexJ_reult_vec3_f16",
        "__frexp_result_vec3_f16",
        "c_frexp_result_vec3_f16",
        "__frexp_result_vec3Of16",
        "___frexp_reKKultvvvec3_f1tt",
        "8_frexp_reult_vxxc3_f32",
        "_frexp_resul___veFqqf32",
        "_qqfrexp_result_vec_f32",
        "__frexp_result_vec3_f32",
        "33_fOexp_result_ve3_6632",
        "__oorexQQ_rttsult_ve639f32",
        "__rexp_result_vec3_f662",
        "__frexp_reszzlt_Oc4xabstrac66",
        "__frexp_resyylt_vec4_abstract",
        "__frexp_resut_vecHH_aZsracZ",
        "__frexp_result_vec4_abstract",
        "_WWfrex44_resulq_vec4_astract",
        "__frexp_rsult_veOO4_abstract",
        "__frexp_resultoovc4_abstYct",
        "_frexp_esultvec4_f16",
        "__Frexp_result_ec4_f16",
        "__frewp_resut_vec4_f16",
        "__frexp_result_vec4_f16",
        "__frexp_reslt_veK4fG16",
        "__fqexp_result_veKK4_f16",
        "_F3rexp_result_vec4_f1mm",
        "__frexp_result_ec4_f32",
        "__frexp_result_qe4_f32",
        "__frbbxp_result_vec4_b2",
        "__frexp_result_vec4_f32",
        "__frexp_reslt_iiec4_f2",
        "__frexO_resulq_vec4_f32",
        "__frexp_resulTT_vec4vvf32",
        "__modf_resulFF_abstract",
        "fm00df_rePult_abstraQt",
        "__modf_result_abstPact",
        "__modf_result_abstract",
        "_modf_result_abstssac77",
        "__modf_resulC_bbRbstract",
        "__modf_result_abstracXX",
        "__OOofCCresuOOt_f16",
        "_smodf_resuutfL6",
        "__modX_result_f16",
        "__modf_result_f16",
        "__modf_reult_f16",
        "__modf_resqqO16",
        "__modf22result_f16",
        "__modf_X0eszzlt_fy",
        "_VVmPf_result_f3i",
        "__monnfCresultf32",
        "__modf_result_f32",
        "_HHAmodf_resqltf32",
        "__modf_resut_f32",
        "__modresuft_f3KK",
        "__modlPrsultggvec2_astract",
        "__odf_result_vec2_abstract",
        "__mocTf_result_vNc2_abstra4t",
        "__modf_result_vec2_abstract",
        "__modf77result_vec2_plbtract",
        "__mdf_resultNNvec2zabstgact",
        "_modf_bbesult_vuuc2_abtraXXt",
        "__modf_esult_vec2_f16",
        "__mQdf_esuKt_vec_8816",
        "q_m9dfresult_vec2_f16",
        "__modf_result_vec2_f16",
        "__11odf_result_vec2_f16",
        "_iimodf_result_vF222f16",
        "_77modf_result_vec2f16",
        "__odfNNr2sult_vec2_f32",
        "__modf_rVVsult_vec2_f32",
        "__modf_Fesult_vewW2_f311",
        "__modf_result_vec2_f32",
        "__modf_rwwsult_vec_f32",
        "__modf_result_Dec2_f32",
        "__modf_result_ec2_f3K",
        "__modf_resul1PP_vech_abstfact",
        "__modf_result_vec_abstract",
        "__YYodf_result_vec3_abstract",
        "__modf_result_vec3_abstract",
        "__mHHdfresult_kkec3_abstract",
        "__modf_result_vec3rrabstract",
        "__modf_ssesulWW_vec_abstract",
        "__mYdf_reslt_vec3_f16",
        "q_modLrfsult_vec3_f16",
        "uu_vvo22f_rfsult_ec3_f16",
        "__modf_result_vec3_f16",
        "__mdf_reslt_vec3_f16",
        "__modfYYresult_ve3f16",
        "__modfEr77sult_vec3_yY16",
        "__odf_desuMot_vec3_f32",
        "__mMMf_result_vec3_f32",
        "__modf_result_vec3_f355",
        "__modf_result_vec3_f32",
        "__modf_rest_vec3Nf32",
        "_m33df_result_Oec3_f32",
        "__modf_re3ult_vec3_f32",
        "__momf_esult_Iec4_abstract",
        "__modf_resultrvec4_absnnracK",
        "__modf_eslt_ve4_absXXact",
        "__modf_result_vec4_abstract",
        "__modf_rsult_pLLI4_abstract",
        "_modf_resflt_vec4_bstract",
        "_Ymodf_resultURDec4_abtract",
        "__hodf_result_vec4_f16",
        "__moquu_rslt_vec4_f1II",
        "__modf_result_vecH_f16",
        "__modf_result_vec4_f16",
        "__oQQf_resultvvvc4_f16",
        "__modf_eeult66ec4_f16",
        "_Omodf_r7sut_vec4_W16",
        "__modf_DDes0lt_v55c4_f32",
        "__modf_rIIsult_Hec4_f32",
        "_modf_result_vec4_f32",
        "__modf_result_vec4_f32",
        "_modf_result_vrc4_f32",
        "_lmodf_result_vec4_f32",
        "tt_modfGeslt_vec4_fJJ2",
        "__paked_vyc3",
        "_packed_vec3",
        "__pIIckedBBvec3",
        "__packed_vec3",
        "__8aTTked_v33c3",
        "dnnUUpackeSSY_vec3",
        "xC_5ackedZvec3",
        "kkrraq",
        "a005iy",
        "anIIray",
        "array",
        "ccrW",
        "rKK",
        "arr66y",
        "aKKoPi",
        "atxxmc",
        "atoqic",
        "atomic",
        "rMoyyiSS",
        "utom",
        "oic",
        "5oFFl",
        "borz4l",
        "WW",
        "bool",
        "ZJJCoX",
        "boPP",
        "bocl",
        "fll66",
        "91yy",
        "f1KK",
        "f16",
        "x_",
        "K",
        "kVz",
        "K3S",
        "f2",
        "fVV",
        "f32",
        "IAU2",
        "j",
        "Y4",
        "i2",
        "1xx",
        "ccm",
        "i32",
        "iJJ",
        "UfCDD",
        "i3g",
        "CCtx",
        "mt2x2",
        "mat2x__",
        "mat2x2",
        "attxPP",
        "mdd32x2",
        "yyK2x2",
        "m2uu",
        "ma0nnx2i",
        "KanuuCC2f",
        "mat2x2f",
        "mlX2x2f",
        "oat2pp2f",
        "wwat22f",
        "matguum",
        "mt2ma2",
        "Tat2xZRRh",
        "mat2x2h",
        "ma8T2xOh",
        "m0at2x2h",
        "mBBt2x2h",
        "Matpp",
        "Oat2x3",
        "GGG2x3",
        "mat2x3",
        "mHHt2113",
        "mateF63",
        "matx",
        "mat2ii3l",
        "mt2x3f",
        "IIvvt2x39",
        "mat2x3f",
        "mat23f",
        "mat2h3f",
        "mllt2xPzz",
        "t3h",
        "mtffxqqh",
        "mtJJx3dd",
        "mat2x3h",
        "mzz2X3h",
        "matx32",
        "maN2yy3h",
        "atxO",
        "rauExP",
        "meet22dd",
        "mat2x4",
        "maV92",
        "maI2x1",
        "mab2x4",
        "matzf",
        "mao2ii4f",
        "mat45",
        "mat2x4f",
        "at2xSf",
        "mat22f",
        "maG1C4f",
        "maff284h",
        "t2x4h",
        "SSatJJx4h",
        "mat2x4h",
        "atx9h",
        "maJJbbTT4h",
        "66a2xh",
        "ma663u",
        "Wa3x2",
        "ma32",
        "mat3x2",
        "ma3x2",
        "rat3x2",
        "m2t3xB",
        "matxBBf",
        "maRR3xf",
        "maVV0Lf",
        "mat3x2f",
        "a3OOK2f",
        "magw3xf",
        "hht3L2f",
        "aKii3xh",
        "ma3x2h",
        "UUa3882",
        "mat3x2h",
        "rrvvt3x2h",
        "m3xwmm",
        "j443x2h",
        "matXx3",
        "m8t3x3",
        "mat3vEE",
        "mat3x3",
        "mzzi3x",
        "maGGQ3JJ3",
        "mat3ss3",
        "matKxPf",
        "mat3ttf",
        "mt3x3",
        "mat3x3f",
        "mMMt3x3f",
        "maJ03x3f",
        "V8x3",
        "maKggx3hh",
        "maf3x3h",
        "matQ7x3h",
        "mat3x3h",
        "mat3YYh",
        "mak3x3",
        "man3x2",
        "mFFx4",
        "GGatPPuUU",
        "mEEFa4",
        "mat3x4",
        "mBet3dd4",
        "55atExcc",
        "txKK",
        "mat3x4R",
        "maDx49",
        "mt3x4f",
        "mat3x4f",
        "aaat3I",
        "m77t3x4f",
        "matIx4f",
        "md3x4h",
        "mat34h",
        "mtt4h",
        "mat3x4h",
        "ma3XX3x4h",
        "Eat34h",
        "maXX3x4",
        "mxBt4x2",
        "Wt4x",
        "mat66x2",
        "mat4x2",
        "atTv0",
        "kt",
        "mpt4x",
        "at112f",
        "EaJ4yBBf",
        "mqIm4x2f",
        "mat4x2f",
        "ma4xFf",
        "Yt4x2f",
        "mHHtDh2f",
        "Ht22h",
        "matx2",
        "matx2h",
        "mat4x2h",
        "matx2h",
        "matddx2h",
        "Oat4x2h",
        "bbtB3",
        "m00tx3",
        "hat4x3",
        "mat4x3",
        "matgYx",
        "Oat4x3",
        "mhx3",
        "fpaEEx3f",
        "mavx3f",
        "mzztx3f",
        "mat4x3f",
        "ma4x3f",
        "OOaJxii",
        "mft4G3f",
        "mat4x322T",
        "datlx3h",
        "bat4x3h",
        "mat4x3h",
        "BBatx3h",
        "PPIXt4S3h",
        "mjjt4x3h",
        "macc4_4",
        "SS6zz4xx",
        "mtx",
        "mat4x4",
        "mxxtvN",
        "AA00t44",
        "tyexy",
        "mabWWx0f",
        "ttatMMxmf",
        "madf",
        "mat4x4f",
        "mat_4f",
        "Vat4EE4f",
        "mat44f",
        "mRIxah",
        "ma4mmh",
        "at4x4p",
        "mat4x4h",
        "mat4xh",
        "aaxh",
        "mad4x4h",
        "pCPtd",
        "p",
        "5tr",
        "ptr",
        "ff99j",
        "YYvXR",
        "r",
        "XX8m5le",
        "mpler",
        "sccmlppr",
        "sampler",
        "sampver",
        "EESSmplr",
        "smplr",
        "samplecomp_risa",
        "sampler_co_prwwson",
        "samplerdd99omparison",
        "sampler_comparison",
        "ampler_o99paPPison",
        "saplerKKcomparison",
        "saMpler_oomDDarison",
        "teiie_1B",
        "txureq1d",
        "txt00rLL_d",
        "texture_1d",
        "tnxture_16vv",
        "trrxtur_nd",
        "xxture_eed",
        "CCNOxture_2d",
        "txture_2d",
        "tex4uae_2d",
        "texture_2d",
        "extuNNe_2NN",
        "texture2d",
        "tuxtre2d",
        "teYYtuAe_2d_arESy",
        "texture_2d_0rray",
        "texture_2d_aarray",
        "texture_2d_array",
        "texturmm_2d_arra",
        "texture_2d_aray",
        "teEuUUe_2darray",
        "tKKture_Dd",
        "text__r0_3d",
        "tAtuel3p",
        "texture_3d",
        "textue_3d",
        "texturBB_3d",
        "nnbb99re_3d",
        "AAEExture_cub",
        "t66Ttu5e_cube",
        "textuHe_cube",
        "texture_cube",
        "textrexxHcub",
        "tzx0uryy_cnbe",
        "texture_cue",
        "texurH_kube_array",
        "exture_cube_array",
        "ooexrrre_cbe_array",
        "texture_cube_array",
        "textre_cubJJarray",
        "tCCxtu0e_cube_arry",
        "texturAAcxbe99aFray",
        "textcre_depth_2d",
        "texture_Septh_2d",
        "textureodpthBB2d",
        "texture_depth_2d",
        "texture_dept_2d",
        "textummedepth_2d",
        "toxture_ggeQQtPP2d",
        "tetur_dptB_2d_rray",
        "texNure_deKKh2d_arrlly",
        "teture_dpth_2d_arrray",
        "texture_depth_2d_array",
        "texture_epth_ppd_array",
        "teyturPP_depth_2d_array",
        "texture_ZZptcc_2d_arry",
        "txtue_depth_cube",
        "texture00depth_cube",
        "texPPuBB_deJth_cusse",
        "texture_depth_cube",
        "texJJre_dffpwwh_fube",
        "textIre_depXXh_cub",
        "textur_ph_cue",
        "textue_depth_cube_array",
        "tKKxtue_depth_cube_array",
        "teture_d44ptm_cube_adray",
        "texture_depth_cube_array",
        "pexture_deoth_cube_array",
        "thhHxtureNdepth_cubejarray",
        "texwwuUUe_depthEc33be_array",
        "texture_dept_multiuuampled_2",
        "ddextKre_depth_ultisampcerr_2d",
        "textuPPe_depr_multttsample2_2d",
        "texture_depth_multisampled_2d",
        "1exture_depth_wwsltisampled_2d",
        "textuce_depth_mnnltisamp11ed_2d",
        "texture_depth_multisapled_2d",
        "texture_externl",
        "teSS66ue_exaaeInal",
        "textuEEe_extenal",
        "texture_external",
        "ccexture_exVerIRl",
        "te9tue_extrnal",
        "taaxture_exterha",
        "texture_multisamLLeS_2d",
        "tefurmm_mutisampled_2d",
        "texture_mul4isampld_qV",
        "texture_multisampled_2d",
        "texture_multisa_pled_d",
        "texure_multisampledQd",
        "texRRuremultisampledEd2d",
        "textur_st9rage_1d",
        "tCCx0ure_strag_1",
        "textuezstorae_1d",
        "texture_storage_1d",
        "texccure_storage_1d",
        "textureOQQ_orge_1d",
        "teturettstrage_1d",
        "textCCrepzzstEr33ge_2d",
        "textudde_storaghh_2d",
        "_etur77_66torage_2d",
        "texture_storage_2d",
        "texture_storaPe_2d",
        "twxture_storage_2d",
        "textur_straguu_2",
        "textureXXstorage_6d_array",
        "extuRRestorage_2d_aray",
        "txtre_storage_2dVVarr1",
        "texture_storage_2d_array",
        "GGexture_storHHge_2d_array",
        "MFFxt7re_storage_2d_array",
        "texture_storage_d_array",
        "3xTugge_stoage_3d",
        "texturP_QtKKrag1__d",
        "textre_storageE3d",
        "texture_storage_3d",
        "tMture_storage_d",
        "t77xture_sGGorSSe_3d",
        "txtttre_storage_3FF",
        "uZZss2",
        "u2",
        "u3l",
        "u32",
        "u3h",
        "uTT",
        "ww2",
        "vKvjj",
        "vYY",
        "EcI2",
        "vec2",
        "vecQQ",
        "Pc",
        "veffH",
        "vec2n",
        "g6F2f",
        "vssh8f",
        "vec2f",
        "veFllf",
        "00e2j",
        "gec2f",
        "vece",
        "ffc2h",
        "ve",
        "vec2h",
        "ve2h",
        "vqc2h",
        "AAe",
        "ec2i",
        "vec2j",
        "ZZec2i",
        "vec2i",
        "PPecII2",
        "ZZec2i",
        "vnnc2i",
        "HekkZ222",
        "ec2",
        "RcNQQ",
        "vec2u",
        "eDu",
        "s3c2cu",
        "vRR2u",
        "vlJJ3",
        "MM",
        "vT63",
        "vec3",
        "QQec3",
        "vuA",
        "e3",
        "yeq3",
        "vec3xx",
        "crr",
        "vec3f",
        "v99cf",
        "vecf",
        "ecHl",
        "e_h",
        "uec3",
        "vc3h",
        "vec3h",
        "EEtmec3h",
        "vec",
        "ec3rr",
        "xc3i",
        "vezz",
        "vec3e",
        "vec3i",
        "uc3Zp",
        "00uc7TT",
        "vvJJ",
        "vecQu",
        "ve3R",
        "e",
        "vec3u",
        "veprPP",
        "xxeDD88u",
        "lldmYYqqu",
        "FFec4",
        "rGecNN",
        "Mecl",
        "vec4",
        "c",
        "qxl4",
        "ve4",
        "ae44f",
        "vec4WW",
        "vecjj",
        "vec4f",
        "vjjc4f",
        "vj1f",
        "vc4f",
        "vec499",
        "vyVV4h",
        "ec4xZ",
        "vec4h",
        "v33vvh",
        "vecs9",
        "veF4",
        "uec4i",
        "eIKK",
        "ve4J",
        "vec4i",
        "vSSCCXXi",
        "JecWW6ZZ",
        "ecd5",
        "vBBcBU",
        "JJ0c411",
        "vecttu",
        "vec4u",
        "vttc",
        "veL4u",
        "v1c4u",
    };
    for (auto _ : state) {
        for (auto* str : kStrings) {
            auto result = ParseBuiltinType(str);
            benchmark::DoNotOptimize(result);
        }
    }
}  // NOLINT(readability/fn_size)

BENCHMARK(BuiltinTypeParser);

}  // namespace
}  // namespace tint::core
