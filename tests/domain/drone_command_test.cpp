#include <gtest/gtest.h>
#include "internal/domain/drone_command.h"

class DroneCommandTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Domain tests don't need Arduino mocks
    }
};

TEST_F(DroneCommandTest, Constructor_ValidValues_SetsAllProperties) {
    // Arrange & Act
    DroneCommand command(100, 200, 300, 400, 5000);
    
    // Assert
    EXPECT_EQ(command.getPitch(), 100);
    EXPECT_EQ(command.getRoll(), 200);
    EXPECT_EQ(command.getYaw(), 300);
    EXPECT_EQ(command.getThrottle(), 400);
    EXPECT_EQ(command.getTimestamp(), 5000);
}

TEST_F(DroneCommandTest, SetPitch_ValidValue_UpdatesPitch) {
    // Arrange
    DroneCommand command(0, 0, 0, 0, 0);
    
    // Act
    command.setPitch(150);
    
    // Assert
    EXPECT_EQ(command.getPitch(), 150);
}

TEST_F(DroneCommandTest, SetRoll_ValidValue_UpdatesRoll) {
    // Arrange
    DroneCommand command(0, 0, 0, 0, 0);
    
    // Act
    command.setRoll(250);
    
    // Assert
    EXPECT_EQ(command.getRoll(), 250);
}

TEST_F(DroneCommandTest, SetYaw_ValidValue_UpdatesYaw) {
    // Arrange
    DroneCommand command(0, 0, 0, 0, 0);
    
    // Act
    command.setYaw(350);
    
    // Assert
    EXPECT_EQ(command.getYaw(), 350);
}

TEST_F(DroneCommandTest, SetThrottle_ValidValue_UpdatesThrottle) {
    // Arrange
    DroneCommand command(0, 0, 0, 0, 0);
    
    // Act
    command.setThrottle(450);
    
    // Assert
    EXPECT_EQ(command.getThrottle(), 450);
}

TEST_F(DroneCommandTest, SetTimestamp_ValidValue_UpdatesTimestamp) {
    // Arrange
    DroneCommand command(0, 0, 0, 0, 0);
    
    // Act
    command.setTimestamp(10000);
    
    // Assert
    EXPECT_EQ(command.getTimestamp(), 10000);
}

TEST_F(DroneCommandTest, Reset_ResetsAllValuesToZero) {
    // Arrange
    DroneCommand command(100, 200, 300, 400, 5000);
    
    // Act
    command.reset();
    
    // Assert
    EXPECT_EQ(command.getPitch(), 0);
    EXPECT_EQ(command.getRoll(), 0);
    EXPECT_EQ(command.getYaw(), 0);
    EXPECT_EQ(command.getThrottle(), 0);
    EXPECT_EQ(command.getTimestamp(), 0);
}

TEST_F(DroneCommandTest, MultipleSetOperations_AllValuesUpdatedCorrectly) {
    // Arrange
    DroneCommand command(0, 0, 0, 0, 0);
    
    // Act
    command.setPitch(111);
    command.setRoll(222);
    command.setYaw(333);
    command.setThrottle(444);
    command.setTimestamp(5555);
    
    // Assert
    EXPECT_EQ(command.getPitch(), 111);
    EXPECT_EQ(command.getRoll(), 222);
    EXPECT_EQ(command.getYaw(), 333);
    EXPECT_EQ(command.getThrottle(), 444);
    EXPECT_EQ(command.getTimestamp(), 5555);
}

TEST_F(DroneCommandTest, NegativeValues_HandledCorrectly) {
    // Arrange
    DroneCommand command(0, 0, 0, 0, 0);
    
    // Act
    command.setPitch(-100);
    command.setRoll(-200);
    command.setYaw(-300);
    command.setThrottle(-400);
    
    // Assert
    EXPECT_EQ(command.getPitch(), -100);
    EXPECT_EQ(command.getRoll(), -200);
    EXPECT_EQ(command.getYaw(), -300);
    EXPECT_EQ(command.getThrottle(), -400);
} 