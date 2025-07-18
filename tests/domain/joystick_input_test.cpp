#include <gtest/gtest.h>
#include "internal/domain/joystick_input.h"

class JoystickInputTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Domain tests don't need Arduino mocks
    }
};

class JoystickTrimTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Domain tests don't need Arduino mocks
    }
};

// JoystickInput Tests
TEST_F(JoystickInputTest, Constructor_ValidValues_SetsAllProperties) {
    // Arrange & Act
    JoystickInput input(100, 200, 300, 400);
    
    // Assert
    EXPECT_EQ(input.getPitch(), 100);
    EXPECT_EQ(input.getRoll(), 200);
    EXPECT_EQ(input.getYaw(), 300);
    EXPECT_EQ(input.getThrottle(), 400);
}

TEST_F(JoystickInputTest, SetPitch_ValidValue_UpdatesPitch) {
    // Arrange
    JoystickInput input(0, 0, 0, 0);
    
    // Act
    input.setPitch(150);
    
    // Assert
    EXPECT_EQ(input.getPitch(), 150);
}

TEST_F(JoystickInputTest, SetRoll_ValidValue_UpdatesRoll) {
    // Arrange
    JoystickInput input(0, 0, 0, 0);
    
    // Act
    input.setRoll(250);
    
    // Assert
    EXPECT_EQ(input.getRoll(), 250);
}

TEST_F(JoystickInputTest, SetYaw_ValidValue_UpdatesYaw) {
    // Arrange
    JoystickInput input(0, 0, 0, 0);
    
    // Act
    input.setYaw(350);
    
    // Assert
    EXPECT_EQ(input.getYaw(), 350);
}

TEST_F(JoystickInputTest, SetThrottle_ValidValue_UpdatesThrottle) {
    // Arrange
    JoystickInput input(0, 0, 0, 0);
    
    // Act
    input.setThrottle(450);
    
    // Assert
    EXPECT_EQ(input.getThrottle(), 450);
}

TEST_F(JoystickInputTest, Reset_ResetsAllValuesToZero) {
    // Arrange
    JoystickInput input(100, 200, 300, 400);
    
    // Act
    input.reset();
    
    // Assert
    EXPECT_EQ(input.getPitch(), 0);
    EXPECT_EQ(input.getRoll(), 0);
    EXPECT_EQ(input.getYaw(), 0);
    EXPECT_EQ(input.getThrottle(), 0);
}

TEST_F(JoystickInputTest, NegativeValues_HandledCorrectly) {
    // Arrange
    JoystickInput input(0, 0, 0, 0);
    
    // Act
    input.setPitch(-100);
    input.setRoll(-200);
    input.setYaw(-300);
    input.setThrottle(-400);
    
    // Assert
    EXPECT_EQ(input.getPitch(), -100);
    EXPECT_EQ(input.getRoll(), -200);
    EXPECT_EQ(input.getYaw(), -300);
    EXPECT_EQ(input.getThrottle(), -400);
}

// JoystickTrim Tests
TEST_F(JoystickTrimTest, Constructor_ValidValues_SetsAllProperties) {
    // Arrange & Act
    JoystickTrim trim(100, 200, 300, 400);
    
    // Assert
    EXPECT_EQ(trim.getPitch(), 100);
    EXPECT_EQ(trim.getRoll(), 200);
    EXPECT_EQ(trim.getYaw(), 300);
    EXPECT_EQ(trim.getThrottle(), 400);
}

TEST_F(JoystickTrimTest, SetPitch_ValidValue_UpdatesPitch) {
    // Arrange
    JoystickTrim trim(0, 0, 0, 0);
    
    // Act
    trim.setPitch(150);
    
    // Assert
    EXPECT_EQ(trim.getPitch(), 150);
}

TEST_F(JoystickTrimTest, SetRoll_ValidValue_UpdatesRoll) {
    // Arrange
    JoystickTrim trim(0, 0, 0, 0);
    
    // Act
    trim.setRoll(250);
    
    // Assert
    EXPECT_EQ(trim.getRoll(), 250);
}

TEST_F(JoystickTrimTest, SetYaw_ValidValue_UpdatesYaw) {
    // Arrange
    JoystickTrim trim(0, 0, 0, 0);
    
    // Act
    trim.setYaw(350);
    
    // Assert
    EXPECT_EQ(trim.getYaw(), 350);
}

TEST_F(JoystickTrimTest, SetThrottle_ValidValue_UpdatesThrottle) {
    // Arrange
    JoystickTrim trim(0, 0, 0, 0);
    
    // Act
    trim.setThrottle(450);
    
    // Assert
    EXPECT_EQ(trim.getThrottle(), 450);
}

TEST_F(JoystickTrimTest, Reset_ResetsAllValuesToZero) {
    // Arrange
    JoystickTrim trim(100, 200, 300, 400);
    
    // Act
    trim.reset();
    
    // Assert
    EXPECT_EQ(trim.getPitch(), 0);
    EXPECT_EQ(trim.getRoll(), 0);
    EXPECT_EQ(trim.getYaw(), 0);
    EXPECT_EQ(trim.getThrottle(), 0);
}

TEST_F(JoystickTrimTest, GetThrottleDeltaFactor_ReturnsDefaultValue) {
    // Arrange
    JoystickTrim trim(0, 0, 0, 0);
    
    // Act & Assert
    EXPECT_EQ(trim.getThrottleDeltaFactor(), 0.05f);
}

TEST_F(JoystickTrimTest, GetThrottleDeadZone_ReturnsDefaultValue) {
    // Arrange
    JoystickTrim trim(0, 0, 0, 0);
    
    // Act & Assert
    EXPECT_EQ(trim.getThrottleDeadZone(), 3);
}

TEST_F(JoystickTrimTest, NegativeValues_HandledCorrectly) {
    // Arrange
    JoystickTrim trim(0, 0, 0, 0);
    
    // Act
    trim.setPitch(-100);
    trim.setRoll(-200);
    trim.setYaw(-300);
    trim.setThrottle(-400);
    
    // Assert
    EXPECT_EQ(trim.getPitch(), -100);
    EXPECT_EQ(trim.getRoll(), -200);
    EXPECT_EQ(trim.getYaw(), -300);
    EXPECT_EQ(trim.getThrottle(), -400);
} 