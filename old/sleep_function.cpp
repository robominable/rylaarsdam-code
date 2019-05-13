int sensorsleep (int ms_sleep)
{
  int ms_remaining = ms_sleep;
  int sleep_tick = 5;
  while(ms_remaining > 0)
  {




        //read and adjust motors




    if(ms_remaining => sleep_tick)
    {
      vex::task::sleep(sleep_tick);
      ms_remaining -= sleep_tick;
    }
    else
    {
      vex::task::sleep(ms_remaining);
      ms_remaining = 0;
    }
  }
}
