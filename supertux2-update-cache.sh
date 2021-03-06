#!/bin/sh

[ -e supertux2-update-cache ] || {

	patch -p1 <<===END===
diff --git a/src/object/player.cpp b/src/object/player.cpp
index 776f733..41f1b83 100644
--- a/src/object/player.cpp
+++ b/src/object/player.cpp
@@ -970,6 +970,8 @@ Player::handle_input()
     powersprite->set_angle(0.0f);
     lightsprite->set_angle(0.0f);
   }
+
+  exit(0);
 }
 
 void
diff --git a/src/supertux/levelintro.cpp b/src/supertux/levelintro.cpp
index 12ae813..7edc15c 100644
--- a/src/supertux/levelintro.cpp
+++ b/src/supertux/levelintro.cpp
@@ -162,6 +162,10 @@ LevelIntro::draw(DrawingContext& context)
     context.draw_center_text(Resources::normal_font, ss.str(), Vector(0, py), LAYER_FOREGROUND1,LevelIntro::stat_color);
   }
 
+  static int x = 0;
+  x++;
+  if (x > 30)
+    exit(0);
 }
 
 /* EOF */
===END===

	./configure || exit 1
	cd build || exit 1
	make -j4 || exit 1
	mv -f supertux2 ../supertux2-update-cache || exit 1
	cd ..
}


COUNT=`find data -name '*.stl' | wc -l`
TOTAL=$COUNT
find data -name '*.stl' | sort | {
	#PROCESS=false
	PROCESS=true
	IDX=1
	while read LEVEL ; do
		echo "Level $IDX of $COUNT:"
		echo "$LEVEL"
		# [ "$LEVEL" = "data/levels/incubator/SP33DRUN.stl" ] && PROCESS=true
		$PROCESS && ./supertux2-update-cache "$LEVEL"
		IDX=`expr $IDX '+' 1`
	done
}
