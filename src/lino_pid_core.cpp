#include "gvac_pid/gvac_pid_core.h"

gvacPID::gvacPID()
{
}

gvacPID::~gvacPID()
{
}

void gvacPID::publishMessage(ros::Publisher *pub_message)
{
  gvac_msgs::PID msg;
  msg.p = p_;
  msg.d = d_;
  msg.i = i_;
  pub_message->publish(msg);
}

void gvacPID::messageCallback(const gvac_msgs::PID::ConstPtr &msg)
{
  p_ = msg->p;
  d_ = msg->d;
  i_ = msg->i;

  //echo P,I,D
  ROS_INFO("P: %f", p_);
  ROS_INFO("D: %f", d_);
  ROS_INFO("I: %f", i_);
}

void gvacPID::configCallback(gvac_pid::gvacPIDConfig &config, double level)
{
  //for PID GUI
  p_ = config.p;
  d_ = config.d;
  i_ = config.i;

}
