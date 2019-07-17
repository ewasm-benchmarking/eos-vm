#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <catch2/catch.hpp>
#include <utils.hpp>
#include <wasm_config.hpp>
#include <eosio/vm/backend.hpp>

using namespace eosio;
using namespace eosio::vm;
extern wasm_allocator wa;
using backend_t = backend<std::nullptr_t>;

TEST_CASE( "Testing wasm <br_table_0_wasm>", "[br_table_0_wasm_tests]" ) {
   auto code = backend_t::read_wasm( br_table_0_wasm );
   backend_t bkend( code );
   bkend.set_wasm_allocator( &wa );

   CHECK(!bkend.reset().call_with_return(nullptr, "env", "type-i32"));
   CHECK(!bkend.reset().call_with_return(nullptr, "env", "type-i64"));
   CHECK(!bkend.reset().call_with_return(nullptr, "env", "type-f32"));
   CHECK(!bkend.reset().call_with_return(nullptr, "env", "type-f64"));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "type-i32-value")->to_ui32() == UINT32_C(1));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "type-i64-value")->to_ui64() == UINT32_C(2));
   CHECK(bit_cast<uint32_t>(bkend.reset().call_with_return(nullptr, "env", "type-f32-value")->to_f32()) == UINT32_C(1077936128));
   CHECK(bit_cast<uint64_t>(bkend.reset().call_with_return(nullptr, "env", "type-f64-value")->to_f64()) == UINT64_C(4616189618054758400));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "empty", UINT32_C(0))->to_ui32() == UINT32_C(22));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "empty", UINT32_C(1))->to_ui32() == UINT32_C(22));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "empty", UINT32_C(11))->to_ui32() == UINT32_C(22));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "empty", UINT32_C(4294967295))->to_ui32() == UINT32_C(22));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "empty", UINT32_C(4294967196))->to_ui32() == UINT32_C(22));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "empty", UINT32_C(4294967295))->to_ui32() == UINT32_C(22));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "empty-value", UINT32_C(0))->to_ui32() == UINT32_C(33));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "empty-value", UINT32_C(1))->to_ui32() == UINT32_C(33));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "empty-value", UINT32_C(11))->to_ui32() == UINT32_C(33));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "empty-value", UINT32_C(4294967295))->to_ui32() == UINT32_C(33));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "empty-value", UINT32_C(4294967196))->to_ui32() == UINT32_C(33));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "empty-value", UINT32_C(4294967295))->to_ui32() == UINT32_C(33));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "singleton", UINT32_C(0))->to_ui32() == UINT32_C(22));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "singleton", UINT32_C(1))->to_ui32() == UINT32_C(20));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "singleton", UINT32_C(11))->to_ui32() == UINT32_C(20));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "singleton", UINT32_C(4294967295))->to_ui32() == UINT32_C(20));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "singleton", UINT32_C(4294967196))->to_ui32() == UINT32_C(20));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "singleton", UINT32_C(4294967295))->to_ui32() == UINT32_C(20));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "singleton-value", UINT32_C(0))->to_ui32() == UINT32_C(32));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "singleton-value", UINT32_C(1))->to_ui32() == UINT32_C(33));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "singleton-value", UINT32_C(11))->to_ui32() == UINT32_C(33));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "singleton-value", UINT32_C(4294967295))->to_ui32() == UINT32_C(33));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "singleton-value", UINT32_C(4294967196))->to_ui32() == UINT32_C(33));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "singleton-value", UINT32_C(4294967295))->to_ui32() == UINT32_C(33));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple", UINT32_C(0))->to_ui32() == UINT32_C(103));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple", UINT32_C(1))->to_ui32() == UINT32_C(102));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple", UINT32_C(2))->to_ui32() == UINT32_C(101));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple", UINT32_C(3))->to_ui32() == UINT32_C(100));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple", UINT32_C(4))->to_ui32() == UINT32_C(104));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple", UINT32_C(5))->to_ui32() == UINT32_C(104));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple", UINT32_C(6))->to_ui32() == UINT32_C(104));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple", UINT32_C(10))->to_ui32() == UINT32_C(104));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple", UINT32_C(4294967295))->to_ui32() == UINT32_C(104));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple", UINT32_C(4294967295))->to_ui32() == UINT32_C(104));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple-value", UINT32_C(0))->to_ui32() == UINT32_C(213));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple-value", UINT32_C(1))->to_ui32() == UINT32_C(212));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple-value", UINT32_C(2))->to_ui32() == UINT32_C(211));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple-value", UINT32_C(3))->to_ui32() == UINT32_C(210));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple-value", UINT32_C(4))->to_ui32() == UINT32_C(214));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple-value", UINT32_C(5))->to_ui32() == UINT32_C(214));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple-value", UINT32_C(6))->to_ui32() == UINT32_C(214));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple-value", UINT32_C(10))->to_ui32() == UINT32_C(214));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple-value", UINT32_C(4294967295))->to_ui32() == UINT32_C(214));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "multiple-value", UINT32_C(4294967295))->to_ui32() == UINT32_C(214));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "large", UINT32_C(0))->to_ui32() == UINT32_C(0));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "large", UINT32_C(1))->to_ui32() == UINT32_C(1));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "large", UINT32_C(100))->to_ui32() == UINT32_C(0));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "large", UINT32_C(101))->to_ui32() == UINT32_C(1));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "large", UINT32_C(10000))->to_ui32() == UINT32_C(0));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "large", UINT32_C(10001))->to_ui32() == UINT32_C(1));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "large", UINT32_C(1000000))->to_ui32() == UINT32_C(1));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "large", UINT32_C(1000001))->to_ui32() == UINT32_C(1));
   CHECK(!bkend.reset().call_with_return(nullptr, "env", "as-block-first"));
   CHECK(!bkend.reset().call_with_return(nullptr, "env", "as-block-mid"));
   CHECK(!bkend.reset().call_with_return(nullptr, "env", "as-block-last"));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-block-value")->to_ui32() == UINT32_C(2));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-loop-first")->to_ui32() == UINT32_C(3));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-loop-mid")->to_ui32() == UINT32_C(4));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-loop-last")->to_ui32() == UINT32_C(5));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-br-value")->to_ui32() == UINT32_C(9));
   CHECK(!bkend.reset().call_with_return(nullptr, "env", "as-br_if-cond"));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-br_if-value")->to_ui32() == UINT32_C(8));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-br_if-value-cond")->to_ui32() == UINT32_C(9));
   CHECK(!bkend.reset().call_with_return(nullptr, "env", "as-br_table-index"));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-br_table-value")->to_ui32() == UINT32_C(10));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-br_table-value-index")->to_ui32() == UINT32_C(11));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-return-value")->to_ui64() == UINT32_C(7));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-if-cond")->to_ui32() == UINT32_C(2));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-if-then", UINT32_C(1), UINT32_C(6))->to_ui32() == UINT32_C(3));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-if-then", UINT32_C(0), UINT32_C(6))->to_ui32() == UINT32_C(6));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-if-else", UINT32_C(0), UINT32_C(6))->to_ui32() == UINT32_C(4));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-if-else", UINT32_C(1), UINT32_C(6))->to_ui32() == UINT32_C(6));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-select-first", UINT32_C(0), UINT32_C(6))->to_ui32() == UINT32_C(5));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-select-first", UINT32_C(1), UINT32_C(6))->to_ui32() == UINT32_C(5));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-select-second", UINT32_C(0), UINT32_C(6))->to_ui32() == UINT32_C(6));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-select-second", UINT32_C(1), UINT32_C(6))->to_ui32() == UINT32_C(6));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-select-cond")->to_ui32() == UINT32_C(7));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-call-first")->to_ui32() == UINT32_C(12));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-call-mid")->to_ui32() == UINT32_C(13));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-call-last")->to_ui32() == UINT32_C(14));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-call_indirect-first")->to_ui32() == UINT32_C(20));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-call_indirect-mid")->to_ui32() == UINT32_C(21));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-call_indirect-last")->to_ui32() == UINT32_C(22));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-call_indirect-func")->to_ui32() == UINT32_C(23));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-local.set-value")->to_ui32() == UINT32_C(17));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-local.tee-value")->to_ui32() == UINT32_C(1));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-global.set-value")->to_ui32() == UINT32_C(1));
   CHECK(bit_cast<uint32_t>(bkend.reset().call_with_return(nullptr, "env", "as-load-address")->to_f32()) == UINT32_C(1071225242));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-loadN-address")->to_ui64() == UINT32_C(30));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-store-address")->to_ui32() == UINT32_C(30));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-store-value")->to_ui32() == UINT32_C(31));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-storeN-address")->to_ui32() == UINT32_C(32));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-storeN-value")->to_ui32() == UINT32_C(33));
   CHECK(bit_cast<uint32_t>(bkend.reset().call_with_return(nullptr, "env", "as-unary-operand")->to_f32()) == UINT32_C(1079613850));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-binary-left")->to_ui32() == UINT32_C(3));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-binary-right")->to_ui64() == UINT32_C(45));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-test-operand")->to_ui32() == UINT32_C(44));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-compare-left")->to_ui32() == UINT32_C(43));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-compare-right")->to_ui32() == UINT32_C(42));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-convert-operand")->to_ui32() == UINT32_C(41));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "as-memory.grow-size")->to_ui32() == UINT32_C(40));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-block-value", UINT32_C(0))->to_ui32() == UINT32_C(19));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-block-value", UINT32_C(1))->to_ui32() == UINT32_C(17));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-block-value", UINT32_C(2))->to_ui32() == UINT32_C(16));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-block-value", UINT32_C(10))->to_ui32() == UINT32_C(16));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-block-value", UINT32_C(4294967295))->to_ui32() == UINT32_C(16));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-block-value", UINT32_C(100000))->to_ui32() == UINT32_C(16));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br-value", UINT32_C(0))->to_ui32() == UINT32_C(8));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br-value", UINT32_C(1))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br-value", UINT32_C(2))->to_ui32() == UINT32_C(17));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br-value", UINT32_C(11))->to_ui32() == UINT32_C(17));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br-value", UINT32_C(4294967292))->to_ui32() == UINT32_C(17));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br-value", UINT32_C(10213210))->to_ui32() == UINT32_C(17));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_if-value", UINT32_C(0))->to_ui32() == UINT32_C(17));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_if-value", UINT32_C(1))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_if-value", UINT32_C(2))->to_ui32() == UINT32_C(8));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_if-value", UINT32_C(9))->to_ui32() == UINT32_C(8));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_if-value", UINT32_C(4294967287))->to_ui32() == UINT32_C(8));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_if-value", UINT32_C(999999))->to_ui32() == UINT32_C(8));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_if-value-cond", UINT32_C(0))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_if-value-cond", UINT32_C(1))->to_ui32() == UINT32_C(8));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_if-value-cond", UINT32_C(2))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_if-value-cond", UINT32_C(3))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_if-value-cond", UINT32_C(4293967296))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_if-value-cond", UINT32_C(9423975))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-value", UINT32_C(0))->to_ui32() == UINT32_C(17));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-value", UINT32_C(1))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-value", UINT32_C(2))->to_ui32() == UINT32_C(8));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-value", UINT32_C(9))->to_ui32() == UINT32_C(8));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-value", UINT32_C(4294967287))->to_ui32() == UINT32_C(8));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-value", UINT32_C(999999))->to_ui32() == UINT32_C(8));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-value-index", UINT32_C(0))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-value-index", UINT32_C(1))->to_ui32() == UINT32_C(8));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-value-index", UINT32_C(2))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-value-index", UINT32_C(3))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-value-index", UINT32_C(4293967296))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-value-index", UINT32_C(9423975))->to_ui32() == UINT32_C(9));
   CHECK(bkend.reset().call_with_return(nullptr, "env", "nested-br_table-loop-block", UINT32_C(1))->to_ui32() == UINT32_C(3));
}

