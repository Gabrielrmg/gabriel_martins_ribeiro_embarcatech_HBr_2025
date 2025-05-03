#include "unity.h"
#include "adc_temp.h"

void setUp(void)   {}  // requerido pela Unity
void tearDown(void) {}  // idem

void test_adc_to_celsius_27C(void)
{
    // para 0.706 V => adc ≈ 876
    uint16_t adc_sim = 876;
    TEST_ASSERT_FLOAT_WITHIN(0.5f, 27.0f, adc_to_celsius(adc_sim));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_adc_to_celsius_27C);
    return UNITY_END();
}
