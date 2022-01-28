#include "gvac_pid/gvac_pid_core.h"

int main(int argc, char **argv)
{

  ros::init(argc, argv, "pid_listener");
  ros::NodeHandle nh;

  int rate;

  ros::NodeHandle pnh("~");
  pnh.param("rate", rate, int(40));

  gvacPID *gvac_pid = new gvacPID();

  ros::Subscriber sub_message = nh.subscribe("pid", 1000, &gvacPID::messageCallback, gvac_pid);

  ros::Rate r(rate);

  // Main loop.
  while (nh.ok())
  {
    ros::spinOnce();
    r.sleep();
  }

  return 0;
} // end main()
